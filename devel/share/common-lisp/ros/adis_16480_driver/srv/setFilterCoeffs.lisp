; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-srv)


;//! \htmlinclude setFilterCoeffs-request.msg.html

(cl:defclass <setFilterCoeffs-request> (roslisp-msg-protocol:ros-message)
  ((CHANGEME
    :reader CHANGEME
    :initarg :CHANGEME
    :type cl:fixnum
    :initform 0))
)

(cl:defclass setFilterCoeffs-request (<setFilterCoeffs-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <setFilterCoeffs-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'setFilterCoeffs-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<setFilterCoeffs-request> is deprecated: use adis_16480_driver-srv:setFilterCoeffs-request instead.")))

(cl:ensure-generic-function 'CHANGEME-val :lambda-list '(m))
(cl:defmethod CHANGEME-val ((m <setFilterCoeffs-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:CHANGEME-val is deprecated.  Use adis_16480_driver-srv:CHANGEME instead.")
  (CHANGEME m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <setFilterCoeffs-request>) ostream)
  "Serializes a message object of type '<setFilterCoeffs-request>"
  (cl:let* ((signed (cl:slot-value msg 'CHANGEME)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <setFilterCoeffs-request>) istream)
  "Deserializes a message object of type '<setFilterCoeffs-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'CHANGEME) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<setFilterCoeffs-request>)))
  "Returns string type for a service object of type '<setFilterCoeffs-request>"
  "adis_16480_driver/setFilterCoeffsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'setFilterCoeffs-request)))
  "Returns string type for a service object of type 'setFilterCoeffs-request"
  "adis_16480_driver/setFilterCoeffsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<setFilterCoeffs-request>)))
  "Returns md5sum for a message object of type '<setFilterCoeffs-request>"
  "683ada407adfbe364ff6409d847c2d92")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'setFilterCoeffs-request)))
  "Returns md5sum for a message object of type 'setFilterCoeffs-request"
  "683ada407adfbe364ff6409d847c2d92")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<setFilterCoeffs-request>)))
  "Returns full string definition for message of type '<setFilterCoeffs-request>"
  (cl:format cl:nil "int16 CHANGEME~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'setFilterCoeffs-request)))
  "Returns full string definition for message of type 'setFilterCoeffs-request"
  (cl:format cl:nil "int16 CHANGEME~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <setFilterCoeffs-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <setFilterCoeffs-request>))
  "Converts a ROS message object to a list"
  (cl:list 'setFilterCoeffs-request
    (cl:cons ':CHANGEME (CHANGEME msg))
))
;//! \htmlinclude setFilterCoeffs-response.msg.html

(cl:defclass <setFilterCoeffs-response> (roslisp-msg-protocol:ros-message)
  ((confirm
    :reader confirm
    :initarg :confirm
    :type cl:fixnum
    :initform 0))
)

(cl:defclass setFilterCoeffs-response (<setFilterCoeffs-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <setFilterCoeffs-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'setFilterCoeffs-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-srv:<setFilterCoeffs-response> is deprecated: use adis_16480_driver-srv:setFilterCoeffs-response instead.")))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <setFilterCoeffs-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-srv:confirm-val is deprecated.  Use adis_16480_driver-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <setFilterCoeffs-response>) ostream)
  "Serializes a message object of type '<setFilterCoeffs-response>"
  (cl:let* ((signed (cl:slot-value msg 'confirm)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <setFilterCoeffs-response>) istream)
  "Deserializes a message object of type '<setFilterCoeffs-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'confirm) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<setFilterCoeffs-response>)))
  "Returns string type for a service object of type '<setFilterCoeffs-response>"
  "adis_16480_driver/setFilterCoeffsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'setFilterCoeffs-response)))
  "Returns string type for a service object of type 'setFilterCoeffs-response"
  "adis_16480_driver/setFilterCoeffsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<setFilterCoeffs-response>)))
  "Returns md5sum for a message object of type '<setFilterCoeffs-response>"
  "683ada407adfbe364ff6409d847c2d92")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'setFilterCoeffs-response)))
  "Returns md5sum for a message object of type 'setFilterCoeffs-response"
  "683ada407adfbe364ff6409d847c2d92")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<setFilterCoeffs-response>)))
  "Returns full string definition for message of type '<setFilterCoeffs-response>"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'setFilterCoeffs-response)))
  "Returns full string definition for message of type 'setFilterCoeffs-response"
  (cl:format cl:nil "int8 confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <setFilterCoeffs-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <setFilterCoeffs-response>))
  "Converts a ROS message object to a list"
  (cl:list 'setFilterCoeffs-response
    (cl:cons ':confirm (confirm msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'setFilterCoeffs)))
  'setFilterCoeffs-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'setFilterCoeffs)))
  'setFilterCoeffs-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'setFilterCoeffs)))
  "Returns string type for a service object of type '<setFilterCoeffs>"
  "adis_16480_driver/setFilterCoeffs")