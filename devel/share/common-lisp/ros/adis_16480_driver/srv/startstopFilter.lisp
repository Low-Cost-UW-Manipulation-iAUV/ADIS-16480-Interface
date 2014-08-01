; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude startstopFilter-request.msg.html

(cl:defclass <startstopFilter-request> (roslisp-msg-protocol:ros-message)
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

(cl:defclass startstopFilter-request (<startstopFilter-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <startstopFilter-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'startstopFilter-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<startstopFilter-request> is deprecated: use adis_16480_driver-srv:startstopFilter-request instead.")))

(cl:ensure-generic-function 'onoff-val :lambda-list '(m))
(cl:defmethod onoff-val ((m <startstopFilter-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:onoff-val is deprecated.  Use adis_16480_driver-srv:onoff instead.")
  (onoff m))

(cl:ensure-generic-function 'msecs-val :lambda-list '(m))
(cl:defmethod msecs-val ((m <startstopFilter-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:msecs-val is deprecated.  Use adis_16480_driver-srv:msecs instead.")
  (msecs m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <startstopFilter-request>) ostream)
  "Serializes a message object of type '<startstopFilter-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'onoff) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'msecs)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <startstopFilter-request>) istream)
  "Deserializes a message object of type '<startstopFilter-request>"
    (cl:setf (cl:slot-value msg 'onoff) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'msecs) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<startstopFilter-request>)))
  "Returns string type for a service object of type '<startstopFilter-request>"
  "adis_16480_driver/startstopFilterRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'startstopFilter-request)))
  "Returns string type for a service object of type 'startstopFilter-request"
  "adis_16480_driver/startstopFilterRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<startstopFilter-request>)))
  "Returns md5sum for a message object of type '<startstopFilter-request>"
  "9696e6353a7d7ce89a69e6f031e51fb8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'startstopFilter-request)))
  "Returns md5sum for a message object of type 'startstopFilter-request"
  "9696e6353a7d7ce89a69e6f031e51fb8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<startstopFilter-request>)))
  "Returns full string definition for message of type '<startstopFilter-request>"
  (cl:format cl:nil "bool onoff~%int16 msecs~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'startstopFilter-request)))
  "Returns full string definition for message of type 'startstopFilter-request"
  (cl:format cl:nil "bool onoff~%int16 msecs~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <startstopFilter-request>))
  (cl:+ 0
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <startstopFilter-request>))
  "Converts a ROS message object to a list"
  (cl:list 'startstopFilter-request
    (cl:cons ':onoff (onoff msg))
    (cl:cons ':msecs (msecs msg))
))
;//! \htmlinclude startstopFilter-response.msg.html

(cl:defclass <startstopFilter-response> (roslisp-msg-protocol:ros-message)
  ((confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass startstopFilter-response (<startstopFilter-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <startstopFilter-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'startstopFilter-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<startstopFilter-response> is deprecated: use adis_16480_driver-srv:startstopFilter-response instead.")))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <startstopFilter-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <startstopFilter-response>) ostream)
  "Serializes a message object of type '<startstopFilter-response>"
  (cl:let* ((signed (cl:slot-value msg 'confirm)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <startstopFilter-response>) istream)
  "Deserializes a message object of type '<startstopFilter-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'confirm) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<startstopFilter-response>)))
  "Returns string type for a service object of type '<startstopFilter-response>"
  "adis_16480_driver/startstopFilterResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'startstopFilter-response)))
  "Returns string type for a service object of type 'startstopFilter-response"
  "adis_16480_driver/startstopFilterResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<startstopFilter-response>)))
  "Returns md5sum for a message object of type '<startstopFilter-response>"
  "9696e6353a7d7ce89a69e6f031e51fb8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'startstopFilter-response)))
  "Returns md5sum for a message object of type 'startstopFilter-response"
  "9696e6353a7d7ce89a69e6f031e51fb8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<startstopFilter-response>)))
  "Returns full string definition for message of type '<startstopFilter-response>"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'startstopFilter-response)))
  "Returns full string definition for message of type 'startstopFilter-response"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <startstopFilter-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <startstopFilter-response>))
  "Converts a ROS message object to a list"
  (cl:list 'startstopFilter-response
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'startstopFilter)))
  'startstopFilter-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'startstopFilter)))
  'startstopFilter-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'startstopFilter)))
  "Returns string type for a service object of type '<startstopFilter>"
  "adis_16480_driver/startstopFilter")