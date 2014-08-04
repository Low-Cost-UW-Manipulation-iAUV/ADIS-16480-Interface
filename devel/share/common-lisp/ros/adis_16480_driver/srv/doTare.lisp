; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude doTare-request.msg.html

(cl:defclass <doTare-request> (roslisp-msg-protocol:ros-message)
  ((msecs_to_tares
    :reader msecs_to_tares
    :initarg :msecs_to_tares
    :type cl:fixnum
    :initform 0))
)

(cl:defclass doTare-request (<doTare-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <doTare-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'doTare-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<doTare-request> is deprecated: use adis_16480_driver-srv:doTare-request instead.")))

(cl:ensure-generic-function 'msecs_to_tares-val :lambda-list '(m))
(cl:defmethod msecs_to_tares-val ((m <doTare-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:msecs_to_tares-val is deprecated.  Use adis_16480_driver-srv:msecs_to_tares instead.")
  (msecs_to_tares m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <doTare-request>) ostream)
  "Serializes a message object of type '<doTare-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msecs_to_tares)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'msecs_to_tares)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <doTare-request>) istream)
  "Deserializes a message object of type '<doTare-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msecs_to_tares)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'msecs_to_tares)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<doTare-request>)))
  "Returns string type for a service object of type '<doTare-request>"
  "adis_16480_driver/doTareRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doTare-request)))
  "Returns string type for a service object of type 'doTare-request"
  "adis_16480_driver/doTareRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<doTare-request>)))
  "Returns md5sum for a message object of type '<doTare-request>"
  "e4dc581a919ef996ab17194e443a2e5c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'doTare-request)))
  "Returns md5sum for a message object of type 'doTare-request"
  "e4dc581a919ef996ab17194e443a2e5c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<doTare-request>)))
  "Returns full string definition for message of type '<doTare-request>"
  (cl:format cl:nil "uint16 msecs_to_tares~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'doTare-request)))
  "Returns full string definition for message of type 'doTare-request"
  (cl:format cl:nil "uint16 msecs_to_tares~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <doTare-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <doTare-request>))
  "Converts a ROS message object to a list"
  (cl:list 'doTare-request
    (cl:cons ':msecs_to_tares (msecs_to_tares msg))
))
;//! \htmlinclude doTare-response.msg.html

(cl:defclass <doTare-response> (roslisp-msg-protocol:ros-message)
  ((confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass doTare-response (<doTare-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <doTare-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'doTare-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<doTare-response> is deprecated: use adis_16480_driver-srv:doTare-response instead.")))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <doTare-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <doTare-response>) ostream)
  "Serializes a message object of type '<doTare-response>"
  (cl:let* ((signed (cl:slot-value msg 'confirm)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <doTare-response>) istream)
  "Deserializes a message object of type '<doTare-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'confirm) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<doTare-response>)))
  "Returns string type for a service object of type '<doTare-response>"
  "adis_16480_driver/doTareResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doTare-response)))
  "Returns string type for a service object of type 'doTare-response"
  "adis_16480_driver/doTareResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<doTare-response>)))
  "Returns md5sum for a message object of type '<doTare-response>"
  "e4dc581a919ef996ab17194e443a2e5c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'doTare-response)))
  "Returns md5sum for a message object of type 'doTare-response"
  "e4dc581a919ef996ab17194e443a2e5c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<doTare-response>)))
  "Returns full string definition for message of type '<doTare-response>"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'doTare-response)))
  "Returns full string definition for message of type 'doTare-response"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <doTare-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <doTare-response>))
  "Converts a ROS message object to a list"
  (cl:list 'doTare-response
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'doTare)))
  'doTare-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'doTare)))
  'doTare-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doTare)))
  "Returns string type for a service object of type '<doTare>"
  "adis_16480_driver/doTare")