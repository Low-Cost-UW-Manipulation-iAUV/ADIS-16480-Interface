; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude setDecRate-request.msg.html

(cl:defclass <setDecRate-request> (roslisp-msg-protocol:ros-message)
  ((DEC_RATE
    :reader DEC_RATE
    :initarg :DEC_RATE
    :type cl:fixnum
    :initform 0))
)

(cl:defclass setDecRate-request (<setDecRate-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <setDecRate-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'setDecRate-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<setDecRate-request> is deprecated: use adis_16480_driver-srv:setDecRate-request instead.")))

(cl:ensure-generic-function 'DEC_RATE-val :lambda-list '(m))
(cl:defmethod DEC_RATE-val ((m <setDecRate-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:DEC_RATE-val is deprecated.  Use adis_16480_driver-srv:DEC_RATE instead.")
  (DEC_RATE m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <setDecRate-request>) ostream)
  "Serializes a message object of type '<setDecRate-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'DEC_RATE)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <setDecRate-request>) istream)
  "Deserializes a message object of type '<setDecRate-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'DEC_RATE)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<setDecRate-request>)))
  "Returns string type for a service object of type '<setDecRate-request>"
  "adis_16480_driver/setDecRateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'setDecRate-request)))
  "Returns string type for a service object of type 'setDecRate-request"
  "adis_16480_driver/setDecRateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<setDecRate-request>)))
  "Returns md5sum for a message object of type '<setDecRate-request>"
  "853c64fc9b4f86824e832c8846091014")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'setDecRate-request)))
  "Returns md5sum for a message object of type 'setDecRate-request"
  "853c64fc9b4f86824e832c8846091014")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<setDecRate-request>)))
  "Returns full string definition for message of type '<setDecRate-request>"
  (cl:format cl:nil "uint8 DEC_RATE~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'setDecRate-request)))
  "Returns full string definition for message of type 'setDecRate-request"
  (cl:format cl:nil "uint8 DEC_RATE~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <setDecRate-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <setDecRate-request>))
  "Converts a ROS message object to a list"
  (cl:list 'setDecRate-request
    (cl:cons ':DEC_RATE (DEC_RATE msg))
))
;//! \htmlinclude setDecRate-response.msg.html

(cl:defclass <setDecRate-response> (roslisp-msg-protocol:ros-message)
  ((confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass setDecRate-response (<setDecRate-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <setDecRate-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'setDecRate-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<setDecRate-response> is deprecated: use adis_16480_driver-srv:setDecRate-response instead.")))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <setDecRate-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <setDecRate-response>) ostream)
  "Serializes a message object of type '<setDecRate-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'confirm)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <setDecRate-response>) istream)
  "Deserializes a message object of type '<setDecRate-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'confirm)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<setDecRate-response>)))
  "Returns string type for a service object of type '<setDecRate-response>"
  "adis_16480_driver/setDecRateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'setDecRate-response)))
  "Returns string type for a service object of type 'setDecRate-response"
  "adis_16480_driver/setDecRateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<setDecRate-response>)))
  "Returns md5sum for a message object of type '<setDecRate-response>"
  "853c64fc9b4f86824e832c8846091014")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'setDecRate-response)))
  "Returns md5sum for a message object of type 'setDecRate-response"
  "853c64fc9b4f86824e832c8846091014")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<setDecRate-response>)))
  "Returns full string definition for message of type '<setDecRate-response>"
  (cl:format cl:nil "uint8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'setDecRate-response)))
  "Returns full string definition for message of type 'setDecRate-response"
  (cl:format cl:nil "uint8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <setDecRate-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <setDecRate-response>))
  "Converts a ROS message object to a list"
  (cl:list 'setDecRate-response
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'setDecRate)))
  'setDecRate-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'setDecRate)))
  'setDecRate-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'setDecRate)))
  "Returns string type for a service object of type '<setDecRate>"
  "adis_16480_driver/setDecRate")