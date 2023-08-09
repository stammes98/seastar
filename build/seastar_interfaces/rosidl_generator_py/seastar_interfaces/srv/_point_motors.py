# generated from rosidl_generator_py/resource/_idl.py.em
# with input from seastar_interfaces:srv/PointMotors.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PointMotors_Request(type):
    """Metaclass of message 'PointMotors_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('seastar_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'seastar_interfaces.srv.PointMotors_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__point_motors__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__point_motors__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__point_motors__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__point_motors__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__point_motors__request

            from seastar_interfaces.msg import DesiredPointing
            if DesiredPointing.__class__._TYPE_SUPPORT is None:
                DesiredPointing.__class__.__import_type_support__()

            from seastar_interfaces.msg import MotorCommand
            if MotorCommand.__class__._TYPE_SUPPORT is None:
                MotorCommand.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PointMotors_Request(metaclass=Metaclass_PointMotors_Request):
    """Message class 'PointMotors_Request'."""

    __slots__ = [
        '_point',
        '_input_state',
    ]

    _fields_and_field_types = {
        'point': 'seastar_interfaces/DesiredPointing',
        'input_state': 'seastar_interfaces/MotorCommand',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['seastar_interfaces', 'msg'], 'DesiredPointing'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['seastar_interfaces', 'msg'], 'MotorCommand'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from seastar_interfaces.msg import DesiredPointing
        self.point = kwargs.get('point', DesiredPointing())
        from seastar_interfaces.msg import MotorCommand
        self.input_state = kwargs.get('input_state', MotorCommand())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.point != other.point:
            return False
        if self.input_state != other.input_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def point(self):
        """Message field 'point'."""
        return self._point

    @point.setter
    def point(self, value):
        if __debug__:
            from seastar_interfaces.msg import DesiredPointing
            assert \
                isinstance(value, DesiredPointing), \
                "The 'point' field must be a sub message of type 'DesiredPointing'"
        self._point = value

    @builtins.property
    def input_state(self):
        """Message field 'input_state'."""
        return self._input_state

    @input_state.setter
    def input_state(self, value):
        if __debug__:
            from seastar_interfaces.msg import MotorCommand
            assert \
                isinstance(value, MotorCommand), \
                "The 'input_state' field must be a sub message of type 'MotorCommand'"
        self._input_state = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PointMotors_Response(type):
    """Metaclass of message 'PointMotors_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('seastar_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'seastar_interfaces.srv.PointMotors_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__point_motors__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__point_motors__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__point_motors__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__point_motors__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__point_motors__response

            from seastar_interfaces.msg import MotorCommand
            if MotorCommand.__class__._TYPE_SUPPORT is None:
                MotorCommand.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PointMotors_Response(metaclass=Metaclass_PointMotors_Response):
    """Message class 'PointMotors_Response'."""

    __slots__ = [
        '_command',
    ]

    _fields_and_field_types = {
        'command': 'seastar_interfaces/MotorCommand',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['seastar_interfaces', 'msg'], 'MotorCommand'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from seastar_interfaces.msg import MotorCommand
        self.command = kwargs.get('command', MotorCommand())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.command != other.command:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def command(self):
        """Message field 'command'."""
        return self._command

    @command.setter
    def command(self, value):
        if __debug__:
            from seastar_interfaces.msg import MotorCommand
            assert \
                isinstance(value, MotorCommand), \
                "The 'command' field must be a sub message of type 'MotorCommand'"
        self._command = value


class Metaclass_PointMotors(type):
    """Metaclass of service 'PointMotors'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('seastar_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'seastar_interfaces.srv.PointMotors')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__point_motors

            from seastar_interfaces.srv import _point_motors
            if _point_motors.Metaclass_PointMotors_Request._TYPE_SUPPORT is None:
                _point_motors.Metaclass_PointMotors_Request.__import_type_support__()
            if _point_motors.Metaclass_PointMotors_Response._TYPE_SUPPORT is None:
                _point_motors.Metaclass_PointMotors_Response.__import_type_support__()


class PointMotors(metaclass=Metaclass_PointMotors):
    from seastar_interfaces.srv._point_motors import PointMotors_Request as Request
    from seastar_interfaces.srv._point_motors import PointMotors_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
