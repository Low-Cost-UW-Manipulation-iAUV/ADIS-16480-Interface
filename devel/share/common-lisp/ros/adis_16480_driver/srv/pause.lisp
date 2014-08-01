; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude pause-request.msg.html

(cl:defclass <pause-request> (roslisp-msg-protocol:ros-message)
  ((onoff
    :reader onoff
    :initarg :onoff
    :type cl:boolean
    :initform cl:nil)
   (msecs
    :reader msecs
    :initarg :msecs
    :type cl:fixnum
    :initform 0))
)

(cl:defclass pause-request (<pause-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pause-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pause-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<pause-request> is deprecated: use adis_16480_driver-srv:pause-request instead.")))

(cl:ensure-generic-function 'onoff-val :lambda-list '(m))
(cl:defmethod onoff-val ((m <pause-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:onoff-val is deprecated.  Use adis_16480_driver-srv:onoff instead.")
  (onoff m))

(cl:ensure-generic-function 'msecs-val :lambda-list '(m))
(cl:defmethod msecs-val ((m <pause-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:msecs-val is deprecated.  Use adis_16480_driver-srv:msecs instead.")
  (msecs m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pause-request>) ostream)
  "Serializes a message object of type '<pause-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'onoff) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'msecs)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pause-request>) istream)
  "Deserializes a message object of type '<pause-request>"
    (cl:setf (cl:slot-value msg 'onoff) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'msecs) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pause-request>)))
  "Returns string type for a service object of type '<pause-request>"
  "adis_16480_driver/pauseRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pause-request)))
  "Returns string type for a service object of type 'pause-request"
  "adis_16480_driver/pauseRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pause-request>)))
  "Returns md5sum for a message object of type '<pause-request>"
  "9696e6353a7d7ce89a69e6f031e51fb8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pause-request)))
  "Returns md5sum for a message object of type 'pause-request"
  "9696e6353a7d7ce89a69e6f031e51fb8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pause-request>)))
  "Returns full string definition for message of type '<pause-request>"
  (cl:format cl:nil "bool onoff~%int16 msecs~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pause-request)))
  "Returns full string definition for message of type 'pause-request"
  (cl:format cl:nil "bool onoff~%int16 msecs~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pause-request>))
  (cl:+ 0
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pause-request>))
  "Converts a ROS message object to a list"
  (cl:list 'pause-request
    (cl:cons ':onoff (onoff msg))
    (cl:cons ':msecs (msecs msg))
))
;//! \htmlinclude pause-response.msg.html

(cl:defclass <pause-response> (roslisp-msg-protocol:ros-message)
  ((confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass pause-response (<pause-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pause-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pause-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<pause-response> is deprecated: use adis_16480_driver-srv:pause-response instead.")))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <pause-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pause-response>) ostream)
  "Serializes a message object of type '<pause-response>"
  (cl:let* ((signed (cl:slot-value msg 'confirm)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pause-response>) istream)
  "Deserializes a message object of type '<pause-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'confirm) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pause-response>)))
  "Returns string type for a service object of type '<pause-response>"
  "adis_16480_driver/pauseResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pause-response)))
  "Returns string type for a service object of type 'pause-response"
  "adis_16480_driver/pauseResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pause-response>)))
  "Returns md5sum for a message object of type '<pause-response>"
  "9696e6353a7d7ce89a69e6f031e51fb8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pause-response)))
  "Returns md5sum for a message object of type 'pause-response"
  "9696e6353a7d7ce89a69e6f031e51fb8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pause-response>)))
  "Returns full string definition for message of type '<pause-response>"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pause-response)))
  "Returns full string definition for message of type 'pause-response"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pause-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pause-response>))
  "Converts a ROS message object to a list"
  (cl:list 'pause-response
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'pause)))
  'pause-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'pause)))
  'pause-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pause)))
  "Returns string type for a service object of type '<pause>"
  "adis_16480_driver/pause")