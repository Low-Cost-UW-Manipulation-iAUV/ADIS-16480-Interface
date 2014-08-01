; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-msg)


;//! \htmlinclude LR_YPR.msg.html

(cl:defclass <LR_YPR> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (ypr
    :reader ypr
    :initarg :ypr
    :type adis_16480_driver-msg:YPR
    :initform (cl:make-instance 'adis_16480_driver-msg:YPR)))
)

(cl:defclass LR_YPR (<LR_YPR>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LR_YPR>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LR_YPR)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-msg:<LR_YPR> is deprecated: use adis_16480_driver-msg:LR_YPR instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LR_YPR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-msg:header-val is deprecated.  Use adis_16480_driver-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'ypr-val :lambda-list '(m))
(cl:defmethod ypr-val ((m <LR_YPR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-msg:ypr-val is deprecated.  Use adis_16480_driver-msg:ypr instead.")
  (ypr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LR_YPR>) ostream)
  "Serializes a message object of type '<LR_YPR>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ypr) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LR_YPR>) istream)
  "Deserializes a message object of type '<LR_YPR>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ypr) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LR_YPR>)))
  "Returns string type for a message object of type '<LR_YPR>"
  "adis_16480_driver/LR_YPR")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LR_YPR)))
  "Returns string type for a message object of type 'LR_YPR"
  "adis_16480_driver/LR_YPR")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LR_YPR>)))
  "Returns md5sum for a message object of type '<LR_YPR>"
  "02eb98049cf72c79887f313f959e9efe")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LR_YPR)))
  "Returns md5sum for a message object of type 'LR_YPR"
  "02eb98049cf72c79887f313f959e9efe")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LR_YPR>)))
  "Returns full string definition for message of type '<LR_YPR>"
  (cl:format cl:nil "Header header~%YPR ypr~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: adis_16480_driver/YPR~%float64 yaw~%float64 pitch~%float64 roll~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LR_YPR)))
  "Returns full string definition for message of type 'LR_YPR"
  (cl:format cl:nil "Header header~%YPR ypr~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: adis_16480_driver/YPR~%float64 yaw~%float64 pitch~%float64 roll~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LR_YPR>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ypr))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LR_YPR>))
  "Converts a ROS message object to a list"
  (cl:list 'LR_YPR
    (cl:cons ':header (header msg))
    (cl:cons ':ypr (ypr msg))
))
