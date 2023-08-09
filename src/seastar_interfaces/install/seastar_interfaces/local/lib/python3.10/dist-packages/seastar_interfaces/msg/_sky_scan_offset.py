# generated from rosidl_generator_py/resource/_idl.py.em
# with input from seastar_interfaces:msg/SkyScanOffset.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SkyScanOffset(type):
    """Metaclass of message 'SkyScanOffset'."""

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
                'seastar_interfaces.msg.SkyScanOffset')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sky_scan_offset
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sky_scan_offset
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sky_scan_offset
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sky_scan_offset
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sky_scan_offset

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkyScanOffset(metaclass=Metaclass_SkyScanOffset):
    """Message class 'SkyScanOffset'."""

    __slots__ = [
        '_azimuth_offset',
        '_elevation_offset',
        '_stokes_angle_offset',
    ]

    _fields_and_field_types = {
        'azimuth_offset': 'double',
        'elevation_offset': 'double',
        'stokes_angle_offset': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.azimuth_offset = kwargs.get('azimuth_offset', float())
        self.elevation_offset = kwargs.get('elevation_offset', float())
        self.stokes_angle_offset = kwargs.get('stokes_angle_offset', float())

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
        if self.azimuth_offset != other.azimuth_offset:
            return False
        if self.elevation_offset != other.elevation_offset:
            return False
        if self.stokes_angle_offset != other.stokes_angle_offset:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def azimuth_offset(self):
        """Message field 'azimuth_offset'."""
        return self._azimuth_offset

    @azimuth_offset.setter
    def azimuth_offset(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'azimuth_offset' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'azimuth_offset' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._azimuth_offset = value

    @builtins.property
    def elevation_offset(self):
        """Message field 'elevation_offset'."""
        return self._elevation_offset

    @elevation_offset.setter
    def elevation_offset(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'elevation_offset' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'elevation_offset' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._elevation_offset = value

    @builtins.property
    def stokes_angle_offset(self):
        """Message field 'stokes_angle_offset'."""
        return self._stokes_angle_offset

    @stokes_angle_offset.setter
    def stokes_angle_offset(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'stokes_angle_offset' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'stokes_angle_offset' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._stokes_angle_offset = value
