; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude switchDataOutMode-request.msg.html

(cl:defclass <switchDataOutMode-request> (roslisp-msg-protocol:ros-message)
  ((Mode
    :reader Mode
    :initarg :Mode
    :type cl:fixnum
    :initform 0))
)

(cl:defclass switchDataOutMode-request (<switchDataOutMode-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <switchDataOutMode-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'switchDataOutMode-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<switchDataOutMode-request> is deprecated: use adis_16480_driver-srv:switchDataOutMode-request instead.")))

(cl:ensure-generic-function 'Mode-val :lambda-list '(m))
(cl:defmethod Mode-val ((m <switchDataOutMode-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:Mode-val is deprecated.  Use adis_16480_driver-srv:Mode instead.")
  (Mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <switchDataOutMode-request>) ostream)
  "Serializes a message object of type '<switchDataOutMode-request>"
  (cl:let* ((signed (cl:slot-value msg 'Mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <switchDataOutMode-request>) istream)
  "Deserializes a message object of type '<switchDataOutMode-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Mode) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<switchDataOutMode-request>)))
  "Returns string type for a service object of type '<switchDataOutMode-request>"
  "adis_16480_driver/switchDataOutModeRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switchDataOutMode-request)))
  "Returns string type for a service object of type 'switchDataOutMode-request"
  "adis_16480_driver/switchDataOutModeRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<switchDataOutMode-request>)))
  "Returns md5sum for a message object of type '<switchDataOutMode-request>"
  "6f0dbb184a0bef2ecba0759c5677b170")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'switchDataOutMode-request)))
  "Returns md5sum for a message object of type 'switchDataOutMode-request"
  "6f0dbb184a0bef2ecba0759c5677b170")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<switchDataOutMode-request>)))
  "Returns full string definition for message of type '<switchDataOutMode-request>"
  (cl:format cl:nil "int16 Mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'switchDataOutMode-request)))
  "Returns full string definition for message of type 'switchDataOutMode-request"
  (cl:format cl:nil "int16 Mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <switchDataOutMode-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <switchDataOutMode-request>))
  "Converts a ROS message object to a list"
  (cl:list 'switchDataOutMode-request
    (cl:cons ':Mode (Mode msg))
))
;//! \htmlinclude switchDataOutMode-response.msg.html

(cl:defclass <switchDataOutMode-response> (roslisp-msg-protocol:ros-message)
  ((confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass switchDataOutMode-response (<switchDataOutMode-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <switchDataOutMode-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'switchDataOutMode-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<switchDataOutMode-response> is deprecated: use adis_16480_driver-srv:switchDataOutMode-response instead.")))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <switchDataOutMode-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <switchDataOutMode-response>) ostream)
  "Serializes a message object of type '<switchDataOutMode-response>"
  (cl:let* ((signed (cl:slot-value msg 'confirm)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <switchDataOutMode-response>) istream)
  "Deserializes a message object of type '<switchDataOutMode-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'confirm) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<switchDataOutMode-response>)))
  "Returns string type for a service object of type '<switchDataOutMode-response>"
  "adis_16480_driver/switchDataOutModeResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switchDataOutMode-response)))
  "Returns string type for a service object of type 'switchDataOutMode-response"
  "adis_16480_driver/switchDataOutModeResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<switchDataOutMode-response>)))
  "Returns md5sum for a message object of type '<switchDataOutMode-response>"
  "6f0dbb184a0bef2ecba0759c5677b170")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'switchDataOutMode-response)))
  "Returns md5sum for a message object of type 'switchDataOutMode-response"
  "6f0dbb184a0bef2ecba0759c5677b170")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<switchDataOutMode-response>)))
  "Returns full string definition for message of type '<switchDataOutMode-response>"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'switchDataOutMode-response)))
  "Returns full string definition for message of type 'switchDataOutMode-response"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <switchDataOutMode-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <switchDataOutMode-response>))
  "Converts a ROS message object to a list"
  (cl:list 'switchDataOutMode-response
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'switchDataOutMode)))
  'switchDataOutMode-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'switchDataOutMode)))
  'switchDataOutMode-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switchDataOutMode)))
  "Returns string type for a service object of type '<switchDataOutMode>"
  "adis_16480_driver/switchDataOutMode")