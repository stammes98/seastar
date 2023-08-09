import random
import signal
import sys
import threading
import argparse

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from python_qt_binding.QtCore import pyqtSlot
from python_qt_binding.QtCore import Qt
from python_qt_binding.QtCore import Signal
from python_qt_binding.QtGui import QFont
from python_qt_binding.QtWidgets import QApplication
from python_qt_binding.QtWidgets import QFormLayout
from python_qt_binding.QtWidgets import QGridLayout
from python_qt_binding.QtWidgets import QHBoxLayout
from python_qt_binding.QtWidgets import QLabel
from python_qt_binding.QtWidgets import QLineEdit
from python_qt_binding.QtWidgets import QMainWindow
from python_qt_binding.QtWidgets import QPushButton
from python_qt_binding.QtWidgets import QSlider
from python_qt_binding.QtWidgets import QScrollArea
from python_qt_binding.QtWidgets import QVBoxLayout
from python_qt_binding.QtWidgets import QWidget

from joint_state_publisher_gui.flow_layout import FlowLayout

RANGE = 10000
LINE_EDIT_WIDTH = 80
SLIDER_WIDTH = 300
INIT_NUM_SLIDERS = 2

DEFAULT_WINDOW_MARGIN = 11
DEFAULT_CHILD_MARGIN = 9
DEFAULT_BTN_HEIGHT = 25
DEFAULT_SLIDER_HEIGHT = 64
MIN_WIDTH = SLIDER_WIDTH + DEFAULT_CHILD_MARGIN * 4 + DEFAULT_WINDOW_MARGIN * 2
MIN_HEIGHT = DEFAULT_BTN_HEIGHT * 2 + DEFAULT_WINDOW_MARGIN * 2 + DEFAULT_CHILD_MARGIN * 2

class CamPublisher(Node):
	def __init__(self):
		super().__init__('camera_faker_publisher')
		self.publisher = self.create_publisher(String, 'sunspot', 10)
		timer_period = 1./50.
		self.timer = self.create_timer(timer_period, self.timer_callback)
		self.X = 320
		self.Y = 240
		
		self.source_update_cb = None
		
	def source_cb(self):
		if self.source_update_cb is not None:
			self.source_update_cb()

	def set_source_update_cb(self, user_cb):
		self.source_update_cb = user_cb
		
		
	def timer_callback(self):
		msg = String()
		msg.data = '%i, %i' % (self.X, self.Y)
		self.publisher.publish(msg)

class Slider(QWidget):
	def __init__(self, name):
		super().__init__()
		self.joint_layout = QVBoxLayout()
		self.row_layout = QHBoxLayout()
		font = QFont("Helvetica", 11, QFont.Bold)
		self.label = QLabel(name)
		self.label.setFont(font)
		self.row_layout.addWidget(self.label)
		
		self.display = QLineEdit("0.00")
		self.display.setAlignment(Qt.AlignRight)
		self.display.setFont(font)
		self.display.setReadOnly(True)
		self.display.setFixedWidth(LINE_EDIT_WIDTH)
		self.row_layout.addWidget(self.display)
		
		self.joint_layout.addLayout(self.row_layout)
		
		self.slider = QSlider(Qt.Horizontal)
		self.slider.setFont(font)
		self.slider.setRange(0, RANGE)
		self.slider.setValue(int(RANGE / 2))
		self.slider.setFixedWidth(SLIDER_WIDTH)
		
		self.joint_layout.addWidget(self.slider)
		
		self.setLayout(self.joint_layout)
		
	def remove(self):
		self.joint_layout.removeWidget(self.slider)
		self.slider.setParent(None)
		self.row_layout.removeWidget(self.display)
		self.display.setParent(None)
		self.row_layout.removeWidget(self.label)
		self.label.setParent(None)
		self.row_layout.setParent(None)
		
class CameraFakerGui(QMainWindow):
	sliderUpdateTrigger = Signal()
	initalize = Signal()
	
	def __init__(self, title, csp):
		super(CameraFakerGui, self).__init__()
		
		self.setWindowTitle(title)
		self.pos_map = {}
		
		self.rand_button = QPushButton('Randomize', self)
		self.rand_button.clicked.connect(self.randomizeEvent)
		
		self.ctr_button = QPushButton('Center', self)
		self.ctr_button.clicked.connect(self.centerEvent)
		
		self.scroll_layout = FlowLayout()
		
		self.scroll_widget = QWidget()
		self.scroll_widget.setLayout(self.scroll_layout)
		
		self.scroll_area = QScrollArea()
		self.scroll_area.setWidgetResizable(True)
		self.scroll_area.setWidget(self.scroll_widget)
		
		self.main_layout = QVBoxLayout()

		self.main_layout.addWidget(self.rand_button)
		self.main_layout.addWidget(self.ctr_button)
		self.main_layout.addWidget(self.scroll_area)
		
		self.central_widget = QWidget()
		self.central_widget.setLayout(self.main_layout)
		self.setCentralWidget(self.central_widget)
		
		self.csp = csp
		self.csp.set_source_update_cb(self.sliderUpdateCb)
		
		self.running = True
		self.sliders = {}
		
		self.initalize.connect(self.initalizeSliders)
		self.sliderUpdateTrigger.connect(self.updateSliders)
		
		self.initalize.emit()
		
	def initalizeSliders(self):
		self.pos_map = {}
		sliderX = Slider("X")
		self.scroll_layout.addWidget(sliderX)
		sliderX.slider.valueChanged.connect(lambda event, name='sliderX': self.onSliderValueChangedOne("sliderX"))
		self.sliders[sliderX] = sliderX
		
		dataX = {'min' : 0, 'max' : 640, 'position' : 320, 'zero' : 320}
		
		self.pos_map["sliderX"] = {'display' : sliderX.display, 'slider' : sliderX.slider, 'data' : dataX}
		
		sliderY = Slider("Y")
		self.scroll_layout.addWidget(sliderY)
		sliderY.slider.valueChanged.connect(lambda event, name='sliderY': self.onSliderValueChangedOne("sliderY"))
		self.sliders[sliderY] = sliderY
		
		dataY = {'min' : 0, 'max' : 480, 'position' : 240, 'zero' : 240}
		
		self.pos_map["sliderY"] = {'display' : sliderY.display, 'slider' : sliderY.slider, 'data' : dataY}
		
		self.centerEvent(None)
		num_sliders = 2
		scroll_layout_height = num_sliders * DEFAULT_SLIDER_HEIGHT
		scroll_layout_height += (num_sliders + 1) * DEFAULT_CHILD_MARGIN
		self.setMinimumSize(MIN_WIDTH, scroll_layout_height + MIN_HEIGHT)
		self.sliderUpdateTrigger.emit()

		
	def sliderUpdateCb(self):
		self.sliderUpdateTrigger.emit()
		
	def initalizeCb(self):
		self.initalize.emit()
		
	def onSliderValueChangedOne(self, name):
		pos_info = self.pos_map[name]
		slidervalue = pos_info['slider'].value()
		dat = pos_info['data']
		dat['position'] = self.sliderToValue(slidervalue, dat)
		pos_info['display'].setText("%d" % int(dat['position']))
		
		if (name == 'sliderX'):
			self.csp.X = self.sliderToValue(slidervalue, dat)
		else:
			self.csp.Y = self.sliderToValue(slidervalue, dat)
		
	@pyqtSlot()
	def updateSliders(self):
		for name, pos_info in self.pos_map.items():
			dat = pos_info['data']
			slidervalue = self.valueToSlider(dat['position'], dat)
			pos_info['slider'].setValue(slidervalue)
			
	def centerEvent(self, event):
		for name, pos_info in self.pos_map.items():
			dat = pos_info['data']
			pos_info['slider'].setValue(self.valueToSlider(dat['zero'], dat))
			
	def randomizeEvent(self, event):
		for name, pos_info in self.pos_map.items():
			dat = pos_info['data']
			pos_info['slider'].setValue(self.valueToSlider(random.uniform(dat['min'], dat['max']), dat))
			
	def valueToSlider(self, value, dat):
		return int((value - dat['min']) * float(RANGE) / (dat['max'] - dat['min']))

	def sliderToValue(self, slider, dat):
		pctvalue = slider / float(RANGE)
		return dat['min'] + (dat['max'] - dat['min']) * pctvalue
	
	def closeEvent(self, event):
		self.running = False
	
	def loop(self):
		self.randomizeEvent(None)
		self.centerEvent(None)
		while self.running:
			rclpy.spin_once(self.csp, timeout_sec=0.1)

def main():
    rclpy.init()
    
    
    app = QApplication(sys.argv)
    csp_gui = CameraFakerGui("Camera State Publisher", CamPublisher())
    csp_gui.show()
    
    threading.Thread(target=csp_gui.loop).start()
    signal.signal(signal.SIGINT, signal.SIG_DFL)
    sys.exit(app.exec_())
    


if __name__ == '__main__':
    main()
