; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-msg)


;//! \htmlinclude HR_YPR_lACC.msg.html

(cl:defclass <HR_YPR_lACC> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (acceleration
    :reader acceleration
    :initarg :acceleration
    :type adis_16480_driver-msg:Acceleration
    :initform (cl:make-instance 'adis_16480_driver-msg:Acceleration))
   (ypr
    :reader ypr
    :initarg :ypr
    :type adis_16480_driver-msg:YPR
    :initform (cl:make-instance 'adis_16480_driver-msg:YPR)))
)

(cl:defclass HR_YPR_lACC (<HR_YPR_lACC>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HR_YPR_lACC>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HR_YPR_lACC)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-msg:<HR_YPR_lACC> is deprecated: use adis_16480_driver-msg:HR_YPR_lACC instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <HR_YPR_lACC>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-msg:header-val is deprecated.  Use adis_16480_driver-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'acceleration-val :lambda-list '(m))
(cl:defmethod acceleration-val ((m <HR_YPR_lACC>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-msg:acceleration-val is deprecated.  Use adis_16480_driver-msg:acceleration instead.")
  (acceleration m))

(cl:ensure-generic-function 'ypr-val :lambda-list '(m))
(cl:defmethod ypr-val ((m <HR_YPR_lACC>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-msg:ypr-val is deprecated.  Use adis_16480_driver-msg:ypr instead.")
  (ypr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HR_YPR_lACC>) ostream)
  "Serializes a message object of type '<HR_YPR_lACC>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'acceleration) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ypr) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HR_YPR_lACC>) istream)
  "Deserializes a message object of type '<HR_YPR_lACC>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'acceleration) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ypr) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HR_YPR_lACC>)))
  "Returns string type for a message object of type '<HR_YPR_lACC>"
  "adis_16480_driver/HR_YPR_lACC")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HR_YPR_lACC)))
  "Returns string type for a message object of type 'HR_YPR_lACC"
  "adis_16480_driver/HR_YPR_lACC")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HR_YPR_lACC>)))
  "Returns md5sum for a message object of type '<HR_YPR_lACC>"
  "1e7330693b46c6b9f7d81b5189410df1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HR_YPR_lACC)))
  "Returns md5sum for a message object of type 'HR_YPR_lACC"
  "1e7330693b46c6b9f7d81b5189410df1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HR_YPR_lACC>)))
  "Returns full string definition for message of type '<HR_YPR_lACC>"
  (cl:format cl:nil "Header header~%Acceleration acceleration~%YPR ypr~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: adis_16480_driver/Acceleration~%int64 linear_x~%int64 linear_y~%int64 linear_z~%================================================================================~%MSG: adis_16480_driver/YPR~%float64 yaw~%float64 pitch~%float64 roll~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HR_YPR_lACC)))
  "Returns full string definition for message of type 'HR_YPR_lACC"
  (cl:format cl:nil "Header header~%Acceleration acceleration~%YPR ypr~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: adis_16480_driver/Acceleration~%int64 linear_x~%int64 linear_y~%int64 linear_z~%================================================================================~%MSG: adis_16480_driver/YPR~%float64 yaw~%float64 pitch~%float64 roll~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HR_YPR_lACC>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'acceleration))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ypr))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HR_YPR_lACC>))
  "Converts a ROS message object to a list"
  (cl:list 'HR_YPR_lACC
    (cl:cons ':header (header msg))
    (cl:cons ':acceleration (acceleration msg))
    (cl:cons ':ypr (ypr msg))
))
