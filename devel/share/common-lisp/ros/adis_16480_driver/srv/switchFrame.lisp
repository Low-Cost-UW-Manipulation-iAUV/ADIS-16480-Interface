; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude switchFrame-request.msg.html

(cl:defclass <switchFrame-request> (roslisp-msg-protocol:ros-message)
  ((new_frame
    :reader new_frame
    :initarg :new_frame
    :type cl:fixnum
    :initform 0))
)

(cl:defclass switchFrame-request (<switchFrame-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <switchFrame-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'switchFrame-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<switchFrame-request> is deprecated: use adis_16480_driver-srv:switchFrame-request instead.")))

(cl:ensure-generic-function 'new_frame-val :lambda-list '(m))
(cl:defmethod new_frame-val ((m <switchFrame-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:new_frame-val is deprecated.  Use adis_16480_driver-srv:new_frame instead.")
  (new_frame m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <switchFrame-request>) ostream)
  "Serializes a message object of type '<switchFrame-request>"
  (cl:let* ((signed (cl:slot-value msg 'new_frame)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <switchFrame-request>) istream)
  "Deserializes a message object of type '<switchFrame-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'new_frame) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<switchFrame-request>)))
  "Returns string type for a service object of type '<switchFrame-request>"
  "adis_16480_driver/switchFrameRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switchFrame-request)))
  "Returns string type for a service object of type 'switchFrame-request"
  "adis_16480_driver/switchFrameRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<switchFrame-request>)))
  "Returns md5sum for a message object of type '<switchFrame-request>"
  "032f8728469b4998f713c46fb1e008aa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'switchFrame-request)))
  "Returns md5sum for a message object of type 'switchFrame-request"
  "032f8728469b4998f713c46fb1e008aa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<switchFrame-request>)))
  "Returns full string definition for message of type '<switchFrame-request>"
  (cl:format cl:nil "int8 new_frame~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'switchFrame-request)))
  "Returns full string definition for message of type 'switchFrame-request"
  (cl:format cl:nil "int8 new_frame~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <switchFrame-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <switchFrame-request>))
  "Converts a ROS message object to a list"
  (cl:list 'switchFrame-request
    (cl:cons ':new_frame (new_frame msg))
))
;//! \htmlinclude switchFrame-response.msg.html

(cl:defclass <switchFrame-response> (roslisp-msg-protocol:ros-message)
  ((current_frame
    :reader current_frame
    :initarg :current_frame
    :type cl:fixnum
    :initform 0)
   (confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass switchFrame-response (<switchFrame-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <switchFrame-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'switchFrame-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<switchFrame-response> is deprecated: use adis_16480_driver-srv:switchFrame-response instead.")))

(cl:ensure-generic-function 'current_frame-val :lambda-list '(m))
(cl:defmethod current_frame-val ((m <switchFrame-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:current_frame-val is deprecated.  Use adis_16480_driver-srv:current_frame instead.")
  (current_frame m))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <switchFrame-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <switchFrame-response>) ostream)
  "Serializes a message object of type '<switchFrame-response>"
  (cl:let* ((signed (cl:slot-value msg 'current_frame)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'confirm)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <switchFrame-response>) istream)
  "Deserializes a message object of type '<switchFrame-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'current_frame) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'confirm) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<switchFrame-response>)))
  "Returns string type for a service object of type '<switchFrame-response>"
  "adis_16480_driver/switchFrameResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switchFrame-response)))
  "Returns string type for a service object of type 'switchFrame-response"
  "adis_16480_driver/switchFrameResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<switchFrame-response>)))
  "Returns md5sum for a message object of type '<switchFrame-response>"
  "032f8728469b4998f713c46fb1e008aa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'switchFrame-response)))
  "Returns md5sum for a message object of type 'switchFrame-response"
  "032f8728469b4998f713c46fb1e008aa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<switchFrame-response>)))
  "Returns full string definition for message of type '<switchFrame-response>"
  (cl:format cl:nil "int8 current_frame~%int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'switchFrame-response)))
  "Returns full string definition for message of type 'switchFrame-response"
  (cl:format cl:nil "int8 current_frame~%int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <switchFrame-response>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <switchFrame-response>))
  "Converts a ROS message object to a list"
  (cl:list 'switchFrame-response
    (cl:cons ':current_frame (current_frame msg))
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'switchFrame)))
  'switchFrame-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'switchFrame)))
  'switchFrame-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switchFrame)))
  "Returns string type for a service object of type '<switchFrame>"
  "adis_16480_driver/switchFrame")