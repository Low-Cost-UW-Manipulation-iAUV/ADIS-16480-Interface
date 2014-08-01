; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude doEKFReset-request.msg.html

(cl:defclass <doEKFReset-request> (roslisp-msg-protocol:ros-message)
  ((msecs_to_reset
    :reader msecs_to_reset
    :initarg :msecs_to_reset
    :type cl:fixnum
    :initform 0))
)

(cl:defclass doEKFReset-request (<doEKFReset-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <doEKFReset-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'doEKFReset-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<doEKFReset-request> is deprecated: use adis_16480_driver-srv:doEKFReset-request instead.")))

(cl:ensure-generic-function 'msecs_to_reset-val :lambda-list '(m))
(cl:defmethod msecs_to_reset-val ((m <doEKFReset-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:msecs_to_reset-val is deprecated.  Use adis_16480_driver-srv:msecs_to_reset instead.")
  (msecs_to_reset m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <doEKFReset-request>) ostream)
  "Serializes a message object of type '<doEKFReset-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msecs_to_reset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'msecs_to_reset)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <doEKFReset-request>) istream)
  "Deserializes a message object of type '<doEKFReset-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msecs_to_reset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'msecs_to_reset)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<doEKFReset-request>)))
  "Returns string type for a service object of type '<doEKFReset-request>"
  "adis_16480_driver/doEKFResetRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doEKFReset-request)))
  "Returns string type for a service object of type 'doEKFReset-request"
  "adis_16480_driver/doEKFResetRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<doEKFReset-request>)))
  "Returns md5sum for a message object of type '<doEKFReset-request>"
  "b6347cf20e398668817e7ea1f016987d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'doEKFReset-request)))
  "Returns md5sum for a message object of type 'doEKFReset-request"
  "b6347cf20e398668817e7ea1f016987d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<doEKFReset-request>)))
  "Returns full string definition for message of type '<doEKFReset-request>"
  (cl:format cl:nil "uint16 msecs_to_reset~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'doEKFReset-request)))
  "Returns full string definition for message of type 'doEKFReset-request"
  (cl:format cl:nil "uint16 msecs_to_reset~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <doEKFReset-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <doEKFReset-request>))
  "Converts a ROS message object to a list"
  (cl:list 'doEKFReset-request
    (cl:cons ':msecs_to_reset (msecs_to_reset msg))
))
;//! \htmlinclude doEKFReset-response.msg.html

(cl:defclass <doEKFReset-response> (roslisp-msg-protocol:ros-message)
  ((confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass doEKFReset-response (<doEKFReset-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <doEKFReset-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'doEKFReset-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<doEKFReset-response> is deprecated: use adis_16480_driver-srv:doEKFReset-response instead.")))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <doEKFReset-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <doEKFReset-response>) ostream)
  "Serializes a message object of type '<doEKFReset-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'confirm)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <doEKFReset-response>) istream)
  "Deserializes a message object of type '<doEKFReset-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'confirm)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<doEKFReset-response>)))
  "Returns string type for a service object of type '<doEKFReset-response>"
  "adis_16480_driver/doEKFResetResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doEKFReset-response)))
  "Returns string type for a service object of type 'doEKFReset-response"
  "adis_16480_driver/doEKFResetResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<doEKFReset-response>)))
  "Returns md5sum for a message object of type '<doEKFReset-response>"
  "b6347cf20e398668817e7ea1f016987d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'doEKFReset-response)))
  "Returns md5sum for a message object of type 'doEKFReset-response"
  "b6347cf20e398668817e7ea1f016987d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<doEKFReset-response>)))
  "Returns full string definition for message of type '<doEKFReset-response>"
  (cl:format cl:nil "uint8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'doEKFReset-response)))
  "Returns full string definition for message of type 'doEKFReset-response"
  (cl:format cl:nil "uint8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <doEKFReset-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <doEKFReset-response>))
  "Converts a ROS message object to a list"
  (cl:list 'doEKFReset-response
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'doEKFReset)))
  'doEKFReset-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'doEKFReset)))
  'doEKFReset-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doEKFReset)))
  "Returns string type for a service object of type '<doEKFReset>"
  "adis_16480_driver/doEKFReset")