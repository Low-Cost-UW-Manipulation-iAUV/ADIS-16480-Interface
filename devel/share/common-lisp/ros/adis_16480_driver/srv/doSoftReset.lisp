; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude doSoftReset-request.msg.html

(cl:defclass <doSoftReset-request> (roslisp-msg-protocol:ros-message)
  ((msecs_to_reset
    :reader msecs_to_reset
    :initarg :msecs_to_reset
    :type cl:fixnum
    :initform 0))
)

(cl:defclass doSoftReset-request (<doSoftReset-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <doSoftReset-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'doSoftReset-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<doSoftReset-request> is deprecated: use adis_16480_driver-srv:doSoftReset-request instead.")))

(cl:ensure-generic-function 'msecs_to_reset-val :lambda-list '(m))
(cl:defmethod msecs_to_reset-val ((m <doSoftReset-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:msecs_to_reset-val is deprecated.  Use adis_16480_driver-srv:msecs_to_reset instead.")
  (msecs_to_reset m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <doSoftReset-request>) ostream)
  "Serializes a message object of type '<doSoftReset-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msecs_to_reset)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'msecs_to_reset)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <doSoftReset-request>) istream)
  "Deserializes a message object of type '<doSoftReset-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msecs_to_reset)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'msecs_to_reset)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<doSoftReset-request>)))
  "Returns string type for a service object of type '<doSoftReset-request>"
  "adis_16480_driver/doSoftResetRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doSoftReset-request)))
  "Returns string type for a service object of type 'doSoftReset-request"
  "adis_16480_driver/doSoftResetRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<doSoftReset-request>)))
  "Returns md5sum for a message object of type '<doSoftReset-request>"
  "b6347cf20e398668817e7ea1f016987d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'doSoftReset-request)))
  "Returns md5sum for a message object of type 'doSoftReset-request"
  "b6347cf20e398668817e7ea1f016987d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<doSoftReset-request>)))
  "Returns full string definition for message of type '<doSoftReset-request>"
  (cl:format cl:nil "uint16 msecs_to_reset~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'doSoftReset-request)))
  "Returns full string definition for message of type 'doSoftReset-request"
  (cl:format cl:nil "uint16 msecs_to_reset~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <doSoftReset-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <doSoftReset-request>))
  "Converts a ROS message object to a list"
  (cl:list 'doSoftReset-request
    (cl:cons ':msecs_to_reset (msecs_to_reset msg))
))
;//! \htmlinclude doSoftReset-response.msg.html

(cl:defclass <doSoftReset-response> (roslisp-msg-protocol:ros-message)
  ((confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass doSoftReset-response (<doSoftReset-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <doSoftReset-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'doSoftReset-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<doSoftReset-response> is deprecated: use adis_16480_driver-srv:doSoftReset-response instead.")))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <doSoftReset-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <doSoftReset-response>) ostream)
  "Serializes a message object of type '<doSoftReset-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'confirm)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <doSoftReset-response>) istream)
  "Deserializes a message object of type '<doSoftReset-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'confirm)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<doSoftReset-response>)))
  "Returns string type for a service object of type '<doSoftReset-response>"
  "adis_16480_driver/doSoftResetResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doSoftReset-response)))
  "Returns string type for a service object of type 'doSoftReset-response"
  "adis_16480_driver/doSoftResetResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<doSoftReset-response>)))
  "Returns md5sum for a message object of type '<doSoftReset-response>"
  "b6347cf20e398668817e7ea1f016987d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'doSoftReset-response)))
  "Returns md5sum for a message object of type 'doSoftReset-response"
  "b6347cf20e398668817e7ea1f016987d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<doSoftReset-response>)))
  "Returns full string definition for message of type '<doSoftReset-response>"
  (cl:format cl:nil "uint8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'doSoftReset-response)))
  "Returns full string definition for message of type 'doSoftReset-response"
  (cl:format cl:nil "uint8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <doSoftReset-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <doSoftReset-response>))
  "Converts a ROS message object to a list"
  (cl:list 'doSoftReset-response
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'doSoftReset)))
  'doSoftReset-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'doSoftReset)))
  'doSoftReset-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'doSoftReset)))
  "Returns string type for a service object of type '<doSoftReset>"
  "adis_16480_driver/doSoftReset")