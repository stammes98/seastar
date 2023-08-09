import tkinter as tk
from tkinter import ttk
from tkinter import *
import threading
from numpy import random
import time
import HamburgerLib
import DataFileSystem
import datetime
import rclpy
from rclpy.node import Node
from std_msgs.msg import String


sensorInputs = {
    "J2_CH1_0": {"addr":"AIN48","val":1,"gR":1,"gC":1,"gP":1},
    "J2_CH1_2": {"addr":"AIN49","val":1,"gR":1,"gC":2,"gP":1},
    "J2_CH1_4": {"addr":"AIN50" ,"val":1,"gR":1,"gC":3,"gP":1},
    "J2_CH2_0": {"addr":"AIN51" ,"val":1,"gR":2,"gC":1,"gP":1},
    "J2_CH2_2": {"addr":"AIN52" ,"val":1,"gR":2,"gC":2,"gP":1},
    "J2_CH2_4": {"addr":"AIN53" ,"val":1,"gR":2,"gC":3,"gP":1},
    "J2_CH3_0": {"addr":"AIN54" ,"val":1,"gR":3,"gC":1,"gP":1},
    "J2_CH3_2": {"addr":"AIN55" ,"val":1,"gR":3,"gC":2,"gP":1},
    "J2_CH3_4": {"addr":"AIN56" ,"val":1,"gR":3,"gC":3,"gP":1},
    "J2_CH4_0": {"addr":"AIN57" ,"val":1,"gR":4,"gC":1,"gP":1},
    "J2_CH4_2": {"addr":"AIN58" ,"val":1,"gR":4,"gC":2,"gP":1},
    "J2_CH4_4": {"addr":"AIN59" ,"val":1,"gR":4,"gC":3,"gP":1},
    
    "J3_CH1_0": {"addr":"AIN60" ,"val":1,"gR":5,"gC":1,"gP":1},
    "J3_CH1_2": {"addr":"AIN61" ,"val":1,"gR":5,"gC":2,"gP":1},
    "J3_CH1_4": {"addr":"AIN62" ,"val":1,"gR":5,"gC":3,"gP":1},
    "J3_CH2_0": {"addr":"AIN63" ,"val":1,"gR":6,"gC":1,"gP":1},
    "J3_CH2_2": {"addr":"AIN64" ,"val":1,"gR":6,"gC":2,"gP":1},
    "J3_CH2_4": {"addr":"AIN65" ,"val":1,"gR":6,"gC":3,"gP":1},
    "J3_CH3_0": {"addr":"AIN66" ,"val":1,"gR":7,"gC":1,"gP":1},
    "J3_CH3_2": {"addr":"AIN67" ,"val":1,"gR":7,"gC":2,"gP":1},
    "J3_CH3_4": {"addr":"AIN68" ,"val":1,"gR":7,"gC":3,"gP":1},
    "J3_CH4_0": {"addr":"AIN69" ,"val":1,"gR":8,"gC":1,"gP":1},
    "J3_CH4_2": {"addr":"AIN70" ,"val":1,"gR":8,"gC":2,"gP":1},
    "J3_CH4_4": {"addr":"AIN71" ,"val":1,"gR":8,"gC":3,"gP":1},
    "J3_CH5_0": {"addr":"AIN72" ,"val":1,"gR":9,"gC":1,"gP":1},
    "J3_CH5_2": {"addr":"AIN73" ,"val":1,"gR":9,"gC":2,"gP":1},
    "J3_CH5_4": {"addr":"AIN74" ,"val":1,"gR":9,"gC":3,"gP":1},
    
    "J4_CH1_0": {"addr":"AIN75" ,"val":1,"gR":10,"gC":1,"gP":1},
    "J4_CH1_2": {"addr":"AIN76" ,"val":1,"gR":10,"gC":2,"gP":1},
    "J4_CH1_4": {"addr":"AIN77" ,"val":1,"gR":10,"gC":3,"gP":1},
    "J4_CH2_0": {"addr":"AIN78" ,"val":1,"gR":11,"gC":1,"gP":1},
    "J4_CH2_2": {"addr":"AIN79" ,"val":1,"gR":11,"gC":2,"gP":1},
    "J4_CH2_4": {"addr":"AIN80" ,"val":1,"gR":11,"gC":3,"gP":1},
    "J4_CH3_0": {"addr":"AIN81" ,"val":1,"gR":12,"gC":1,"gP":1},
    "J4_CH3_2": {"addr":"AIN82" ,"val":1,"gR":12,"gC":2,"gP":1},
    "J4_CH3_4": {"addr":"AIN83" ,"val":1,"gR":12,"gC":3,"gP":1},
    "J4_CH4_0": {"addr":"AIN84" ,"val":1,"gR":13,"gC":1,"gP":1},
    "J4_CH4_2": {"addr":"AIN85" ,"val":1,"gR":13,"gC":2,"gP":1},
    "J4_CH4_4": {"addr":"AIN86" ,"val":1,"gR":13,"gC":3,"gP":1},
    "J4_CH5_0": {"addr":"AIN87" ,"val":1,"gR":14,"gC":1,"gP":1},
    "J4_CH5_2": {"addr":"AIN88" ,"val":1,"gR":14,"gC":2,"gP":1},
    "J4_CH5_4": {"addr":"AIN89" ,"val":1,"gR":14,"gC":3,"gP":1},
    
    "J5_CH1_0": {"addr":"AIN90" ,"val":1,"gR":15,"gC":1,"gP":1},
    "J5_CH1_2": {"addr":"AIN91" ,"val":1,"gR":15,"gC":2,"gP":1},
    "J5_CH1_4": {"addr":"AIN92" ,"val":1,"gR":15,"gC":3,"gP":1},
    "J5_CH2_0": {"addr":"AIN93" ,"val":1,"gR":16,"gC":1,"gP":1},
    "J5_CH2_2": {"addr":"AIN94" ,"val":1,"gR":16,"gC":2,"gP":1},
    "J5_CH2_4": {"addr":"AIN95" ,"val":1,"gR":16,"gC":3,"gP":1},
    "J5_CH3_0": {"addr":"AIN96" ,"val":1,"gR":17,"gC":1,"gP":1},
    "J5_CH3_2": {"addr":"AIN97" ,"val":1,"gR":17,"gC":2,"gP":1},
    "J5_CH3_4": {"addr":"AIN98" ,"val":1,"gR":17,"gC":3,"gP":1},
    "J5_CH4_0": {"addr":"AIN99" ,"val":1,"gR":18,"gC":1,"gP":1},
    "J5_CH4_2": {"addr":"AIN100" ,"val":1,"gR":18,"gC":2,"gP":1},
    "J5_CH4_4": {"addr":"AIN101" ,"val":1,"gR":18,"gC":3,"gP":1},
    "J5_CH5_0": {"addr":"AIN102" ,"val":1,"gR":19,"gC":1,"gP":1},
    "J5_CH5_2": {"addr":"AIN103" ,"val":1,"gR":19,"gC":2,"gP":1},
    "J5_CH5_4": {"addr":"AIN104" ,"val":1,"gR":19,"gC":3,"gP":1},
}

housekeepingInputs = {
    "12POS": {"addr":"AIN0","val":1,"gR":1,"gC":1,"gP":1},
    "12NEG": {"addr":"AIN1","val":1,"gR":2,"gC":1,"gP":1},
    "GND": {"addr":"AIN2","val":1,"gR":3,"gC":1,"gP":1},
    "J2_GND": {"addr":"AIN113","val":1,"gR":4,"gC":1,"gP":1},
    "J3_GND": {"addr":"AIN114","val":1,"gR":5,"gC":1,"gP":1},
    "J4_GND": {"addr":"AIN115","val":1,"gR":6,"gC":1,"gP":1},
    "J5_GND": {"addr":"AIN116","val":1,"gR":7,"gC":1,"gP":1},
    "Temp1": {"addr":"AIN3","val":1,"gR":8,"gC":1,"gP":1},
    "Temp2": {"addr":"AIN120","val":1,"gR":9,"gC":1,"gP":1},
    "Temp3": {"addr":"AIN121","val":1,"gR":10,"gC":1,"gP":1},
    "Temp4": {"addr":"AIN122","val":1,"gR":11,"gC":1,"gP":1},
    "Temp5": {"addr":"AIN123","val":1,"gR":12,"gC":1,"gP":1},
    "Temp6": {"addr":"AIN124","val":1,"gR":13,"gC":1,"gP":1},
    "Temp7": {"addr":"AIN125","val":1,"gR":14,"gC":1,"gP":1},
    "Temp8": {"addr":"AIN126","val":1,"gR":15,"gC":1,"gP":1},
    "Temp9": {"addr":"AIN127","val":1,"gR":16,"gC":1,"gP":1},
    "Temperature": {"addr":"AIN14", "val":1, "gR":17, "gC":1, "gP":1},
}

otherGui = {
    "loopTime": {"val":1, "gp":1},
    "recordTime": {"start":1, "gp":1},
    "entryTitle":1,
    "entryAuthor":1,
    "entryNotes":1,
    "recordIndicator":1,
    "recordState":FALSE,
    "recordPointer":DataFileSystem.DataFile("HamburgerData")
}

SEorDIF = 199 #199 sets it single ended
Range = 10.0 #Sets to +/- 10v range
SetTime = 0 #Default, daq controlled
ResIndex = 6 #18 bits?

class HamburgerHelper(Node):
	def __init__(self):
		super().__init__("hamburger_helper")
		self.subscription = self.create_subscription(String, "hamburger", self.burger_callback, 10)
		self.doLogging = False
		
		self.gui = tk.Tk()
		self.setupGUI(self.gui)
		
		self.stop_threads = False
		self.thread1 = threading.Thread(target = self.dataLoop)
		
		self.DAQ = HamburgerLib.ham()
		self.DAQ.setupAnalog(SEorDIF, Range, SetTime, ResIndex)
		
		self.thread1.start()
		
		self.gui.after(100, self.mainLUpdate)
		self.gui.mainloop()
		
		self.stop_threads = True
		self.thread1.join()
		
	def dataLoop(self):
		dataArr = []
		houseArr = []
		for x in sensorInputs:
			dataArr.append(sensorInputs[x]['addr'])
		for x in housekeepingInputs:
			houseArr.append(housekeepingInputs[x]['addr'])
		bothArr = dataArr + houseArr
		
		lCount = 10
		curData = list(range(len(sensorInputs) + len(housekeepingInputs)))
		oldTime = time.time()
		
		while True:
			curTime = time.time()
			i = 0
			if lCount < 10:
				results = self.DAQ.getAnalog(dataArr)
				lCount += 1
				for x in sensorInputs:
					sensorInputs[x]['val'] = results[i]
					curData[i] = str(results[i])
					i += 1
			else:
				results = self.DAQ.getAnalog(bothArr)
				lCount = 0
				for x in sensorInputs:
					sensorInputs[x]['val'] = results[i]
					curData[i] = str(results[i])
					i += 1
				for x in housekeepingInputs:
					if (housekeepingInputs[x]['addr'] == "AIN14"):
						V = float(results[i])
						T = (V * -92.6) + 467.6
						results[i] = T
					housekeepingInputs[x]['val'] = results[i]
					curData[i] = str(results[i])
					i += 1
				
			#print(curData)
			if (self.doLogging):
				otherGui["recordPointer"].addData(datetime.datetime.now().strftime("%H:%M:%S.%f")+","+",".join(curData))
			otherGui["loopTime"]["val"] = curTime - oldTime
			oldTime = curTime
			if self.stop_threads:
				break
			time.sleep(0.02)
		
	def burger_callback(self, msg):
		self.get_logger().info("I heard %s" % msg.data)
		ds = str(msg).lower()
		if (ds == 'start'):
			self.startLogging()
		elif (ds == 'stop'):
			self.stopLogging()
		elif (ds == 'toggle'):
			if (self.doLogging):
				self.stopLogging()
			else:
				self.startLogging()
		
		
	def startLogging(self):
		self.get_logger().info("Starting log")
		self.doLogging = True
		
		if not (otherGui["recordState"]):
			otherGui["recordPointer"].Title = otherGui["entryTitle"].get()
			otherGui["recordPointer"].Author = otherGui["entryAuthor"].get()
			otherGui["recordPointer"].Notes = otherGui["entryNotes"].get()
			otherGui["recordPointer"].create()
			fLine = ["HH:MM:SS"]
			for x in sensorInputs:
				fLine.append(x)
			for x in housekeepingInputs:
				fLine.append(x)
			otherGui["recordPointer"].addData(",".join(fLine))
			otherGui["recordIndicator"].config(text="Recording", background="Red")
			self.gui.update_idletasks()
			otherGui["recordTime"]["val"] = time.time()
			otherGui["recordState"] = TRUE
	def stopLogging(self):
		self.get_logger().info("Stopping log")
		self.doLogging = False
		if otherGui["recordState"]:
			otherGui["recordPointer"].end
			otherGui["recordIndicator"].config(text="Stopped", background="Green")
			self.gui.update_idletasks()
			otherGui["recordState"] = FALSE

	def mainLUpdate(self):
		for x in housekeepingInputs:
			housekeepingInputs[x]['gP'].config(text=str(housekeepingInputs[x]['val']))
			
		for x in sensorInputs:
			sensorInputs[x]['gP'].config(text=str(sensorInputs[x]['val']))
		if otherGui["recordState"]:
			td = time.time() - otherGui["recordTime"]['val']
			h = "{:02.0f}".format(td//3600)
			m = "{:02.0f}".format(td//60)
			s = "{:02.0f}".format(td%60)
			otherGui["recordTime"]["gp"].config(text=h+":"+m+":"+s)
		else:
			otherGui["recordTime"]["gp"].config(text="00:00:00")
		otherGui["loopTime"]["gp"].config(text="{:02.2f}".format(otherGui["loopTime"]["val"]))
		
		self.gui.after(50, self.mainLUpdate)
		self.gui.update_idletasks()
				
	def setupGUI(self, root):
		frame_fileEntry = LabelFrame(root, text="Data File Setup", bg="Grey", padx=5, pady=5)
		frame_fileControl = LabelFrame(root, text="Data File Control", bg="Grey", padx=5, pady=5)
		frame_data = LabelFrame(root, text="Radiometer Output", bg="Grey", padx=5, pady=5)
		frame_housekeeping = LabelFrame(root, text="Housekeeping Values", bg="Grey", padx=5, pady=5)

		frame_fileEntry.grid(column = 0, row = 0, columnspan=2, sticky=tk.EW, padx=5, pady=5)
		frame_fileControl.grid(column = 0, row = 1, columnspan=2, sticky=tk.EW, padx=5, pady=5)
		frame_data.grid(column = 0, row = 2, sticky=tk.EW, padx=5, pady=5)
		frame_housekeeping.grid(column = 1, row = 2, sticky=tk.NSEW, padx=5, pady=5)

		########## File Entry Widgets ######################################################################

		####################
		frame_fileEntry.columnconfigure(1, weight=4)
		#Row 0
		text_header = ttk.Label(frame_fileEntry, text="Please enter all useful information before starting program.")
		#Row 1
		text_title = ttk.Label(frame_fileEntry, text="Title:")
		otherGui["entryTitle"] = ttk.Entry(frame_fileEntry)
		otherGui["entryTitle"].insert(0, "default.csv")
		#Row 2
		text_author = ttk.Label(frame_fileEntry, text="Author:")
		otherGui["entryAuthor"] = ttk.Entry(frame_fileEntry)
		otherGui["entryAuthor"].insert(0, "SeaSTAR")
		#Row 3
		text_notes = ttk.Label(frame_fileEntry, text="Notes:")
		otherGui["entryNotes"] = ttk.Entry(frame_fileEntry)
		otherGui["entryNotes"].insert(0, "I'm the default settings, you should change me!")
		####################
		#Row 0
		text_header.grid(column=0, row=0, columnspan=2, sticky=tk.W, pady=5)
		#Row 1
		text_title.grid(column=0, row=1, columnspan=1, sticky=tk.E)
		otherGui["entryTitle"].grid(column=1, row=1, columnspan=1, sticky=tk.EW)
		
		#Row 2
		text_author.grid(column=0, row=2, columnspan=1, sticky=tk.E)
		otherGui["entryAuthor"].grid(column=1, row=2, columnspan=1, sticky=tk.EW)
		#Row 3
		text_notes.grid(column=0, row=3, columnspan=1, sticky=tk.E)
		otherGui["entryNotes"].grid(column=1, row=3, columnspan=1, sticky=tk.EW)

		########## File Control Widgets ######################################################################

		#Row 0
		button_start = ttk.Button(frame_fileControl, text="Start Record", command=self.startLogging)
		button_stop = ttk.Button(frame_fileControl, text="Stop Record", command=self.stopLogging)
		otherGui["recordIndicator"] = ttk.Label(frame_fileControl, background="green", text="Stopped")
		#Row 1
		text_timeupLabel = ttk.Label(frame_fileControl, text="Recording Up Time:", justify=tk.LEFT)
		otherGui["recordTime"]["gp"] = ttk.Label(frame_fileControl, text="00:00:00")
		text_looptimeLabel = ttk.Label(frame_fileControl, text="Loop Time (s):", justify=tk.LEFT)
		otherGui["loopTime"]["gp"] = ttk.Label(frame_fileControl, text="0")


		#Row 0
		button_start.grid(column = 0, row = 0, columnspan=1, pady=5)
		button_stop.grid(column = 1, row = 0, columnspan=1, pady=5)
		otherGui["recordIndicator"].grid(column = 2, row = 0, columnspan=1, padx=4, pady=5)
		#Row 1
		text_timeupLabel.grid(column=0, row = 1, columnspan=1, sticky=tk.E, pady = 5)
		otherGui["recordTime"]["gp"].grid(column=1, row = 1, columnspan=1, sticky=tk.W, pady = 5)
		text_looptimeLabel.grid(column=2, row=1, columnspan=1, sticky=tk.E, pady=5)
		otherGui["loopTime"]["gp"].grid(column=3, row=1, columnspan=1, sticky=tk.W, pady=5)

		########## Data Output Widgets ######################################################################

		#Row 0
		text_1x = ttk.Label(frame_data, text="1x", background="Grey")
		text_100x = ttk.Label(frame_data, text="100x", background="Grey")
		text_100x100 = ttk.Label(frame_data, text="100x100", background="Grey")

		#Row 0
		text_1x.grid(column=1, row=0, columnspan=1)
		text_100x.grid(column=2, row=0, columnspan=1)
		text_100x100.grid(column=3, row=0, columnspan=1)

		######J2
		#Row 1
		text_J2_CH1 = ttk.Label(frame_data, text="J2_CH1", background="Grey")
		text_J2_CH1.grid(column=0, row=1, columnspan=1)
		#Row 2
		text_J2_CH2 = ttk.Label(frame_data, text="J2_CH2", background="Grey")
		text_J2_CH2.grid(column=0, row=2, columnspan=1)
		#Row 3
		text_J2_CH3 = ttk.Label(frame_data, text="J2_CH3", background="Grey")
		text_J2_CH3.grid(column=0, row=3, columnspan=1)
		#Row 4
		text_J2_CH4 = ttk.Label(frame_data, text="J2_CH4", background="Grey")
		text_J2_CH4.grid(column=0, row=4, columnspan=1)

		######J3
		#Row 5
		text_J3_CH1 = ttk.Label(frame_data, text="J3_CH1", background="Grey")
		text_J3_CH1.grid(column=0, row=5, columnspan=1)
		#Row 6
		text_J3_CH2 = ttk.Label(frame_data, text="J3_CH2", background="Grey")
		text_J3_CH2.grid(column=0, row=6, columnspan=1)
		#Row 7
		text_J3_CH3 = ttk.Label(frame_data, text="J3_CH3", background="Grey")
		text_J3_CH3.grid(column=0, row=7, columnspan=1)
		#Row 8
		text_J3_CH4 = ttk.Label(frame_data, text="J3_CH4", background="Grey")
		text_J3_CH4.grid(column=0, row=8, columnspan=1)
		#Row 9
		text_J3_CH5 = ttk.Label(frame_data, text="J3_CH5", background="Grey")
		text_J3_CH5.grid(column=0, row=9, columnspan=1)

		######J4
		#Row 10
		text_J4_CH1 = ttk.Label(frame_data, text="J4_CH1", background="Grey")
		text_J4_CH1.grid(column=0, row=10, columnspan=1)
		#Row 11
		text_J4_CH2 = ttk.Label(frame_data, text="J4_CH2", background="Grey")
		text_J4_CH2.grid(column=0, row=11, columnspan=1)
		#Row 12
		text_J4_CH3 = ttk.Label(frame_data, text="J4_CH3", background="Grey")
		text_J4_CH3.grid(column=0, row=12, columnspan=1)
		#Row 13
		text_J4_CH4 = ttk.Label(frame_data, text="J4_CH4", background="Grey")
		text_J4_CH4.grid(column=0, row=13, columnspan=1)
		#Row 14
		text_J4_CH5 = ttk.Label(frame_data, text="J4_CH5", background="Grey")
		text_J4_CH5.grid(column=0, row=14, columnspan=1)

		######J5
		#Row 15
		text_J5_CH1 = ttk.Label(frame_data, text="J5_CH1", background="Grey")
		text_J5_CH1.grid(column=0, row=15, columnspan=1)
		#Row 16
		text_J5_CH2 = ttk.Label(frame_data, text="J5_CH2", background="Grey")
		text_J5_CH2.grid(column=0, row=16, columnspan=1)
		#Row 17
		text_J5_CH3 = ttk.Label(frame_data, text="J5_CH3", background="Grey")
		text_J5_CH3.grid(column=0, row=17, columnspan=1)
		#Row 18
		text_J5_CH4 = ttk.Label(frame_data, text="J5_CH4", background="Grey")
		text_J5_CH4.grid(column=0, row=18, columnspan=1)
		#Row 19
		text_J5_CH5 = ttk.Label(frame_data, text="J5_CH5", background="Grey")
		text_J5_CH5.grid(column=0, row=19, columnspan=1)
		for x in sensorInputs:
			sensorInputs[x]['gP'] = ttk.Label(frame_data, text=str(sensorInputs[x]['val']), background="White", width=22)
			sensorInputs[x]['gP'].grid(column = sensorInputs[x]['gC'], row=sensorInputs[x]['gR'], columnspan=1, sticky=tk.EW, padx=1, pady=1)
			
		########## Housekeeping Widgets ######################################################################

		#Row 0
		text_houseVal = ttk.Label(frame_housekeeping, text="Values", background="Grey")
		text_houseVal.grid(column=1, row=0, columnspan=1)
		#Row 1
		text_12POS = ttk.Label(frame_housekeeping, text="12 Positive", background="Grey")
		text_12POS.grid(column=0, row=1, columnspan=1)
		#Row 2
		text_12NEG = ttk.Label(frame_housekeeping, text="12 Negative", background="Grey")
		text_12NEG.grid(column=0, row=2, columnspan=1)
		#Row 3
		text_12GND = ttk.Label(frame_housekeeping, text="12 GND", background="Grey")
		text_12GND.grid(column=0, row=3, columnspan=1)
		#Row 4
		text_J2_GND = ttk.Label(frame_housekeeping, text="J2 GND", background="Grey")
		text_J2_GND.grid(column=0, row=4, columnspan=1)
		#Row 5
		text_J3_GND = ttk.Label(frame_housekeeping, text="J3 GND", background="Grey")
		text_J3_GND.grid(column=0, row=5, columnspan=1)
		#Row 6
		text_J4_GND = ttk.Label(frame_housekeeping, text="J4 GND", background="Grey")
		text_J4_GND.grid(column=0, row=6, columnspan=1)
		#Row 7
		text_J5_GND = ttk.Label(frame_housekeeping, text="J5 GND", background="Grey")
		text_J5_GND.grid(column=0, row=7, columnspan=1)
		#Row 8
		text_Temp1 = ttk.Label(frame_housekeeping, text="Temp 1", background="Grey")
		text_Temp1.grid(column=0, row=8, columnspan=1)
		#Row 8
		text_Temp2 = ttk.Label(frame_housekeeping, text="Temp 2", background="Grey")
		text_Temp2.grid(column=0, row=9, columnspan=1)
		#Row 8
		text_Temp3 = ttk.Label(frame_housekeeping, text="Temp 3", background="Grey")
		text_Temp3.grid(column=0, row=10, columnspan=1)
		#Row 8
		text_Temp4 = ttk.Label(frame_housekeeping, text="Temp 4", background="Grey")
		text_Temp4.grid(column=0, row=11, columnspan=1)
		#Row 8
		text_Temp5 = ttk.Label(frame_housekeeping, text="Temp 5", background="Grey")
		text_Temp5.grid(column=0, row=12, columnspan=1)
		#Row 8
		text_Temp6 = ttk.Label(frame_housekeeping, text="Temp 6", background="Grey")
		text_Temp6.grid(column=0, row=13, columnspan=1)
		#Row 8
		text_Temp7 = ttk.Label(frame_housekeeping, text="Temp 7", background="Grey")
		text_Temp7.grid(column=0, row=14, columnspan=1)
		#Row 8
		text_Temp8 = ttk.Label(frame_housekeeping, text="Temp 8", background="Grey")
		text_Temp8.grid(column=0, row=15, columnspan=1)
		#Row 8
		text_Temp9 = ttk.Label(frame_housekeeping, text="Temp 9", background="Grey")
		text_Temp9.grid(column=0, row=16, columnspan=1)
		#Row 9
		text_Temp = ttk.Label(frame_housekeeping, text="Temperature", background="Grey")
		text_Temp.grid(column=0, row=17, columnspan=1)
		
		for x in housekeepingInputs:
			housekeepingInputs[x]['gP'] = ttk.Label(frame_housekeeping, text=str(housekeepingInputs[x]['val']), background="White",width=22)
			housekeepingInputs[x]['gP'].grid(column = housekeepingInputs[x]['gC'], row=housekeepingInputs[x]['gR'], columnspan=1, sticky=tk.EW, padx=1, pady=1)
		
def main():
    rclpy.init()
    ham = HamburgerHelper()
    rclpy.spin(ham)
    ham.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
	main()
