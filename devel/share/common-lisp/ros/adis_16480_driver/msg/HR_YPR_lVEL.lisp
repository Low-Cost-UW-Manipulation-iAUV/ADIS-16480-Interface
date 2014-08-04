; Auto-generated. Do not edit!


(cl:in-package adis_16480_driver-msg)


;//! \htmlinclude HR_YPR_lVEL.msg.html

(cl:defclass <HR_YPR_lVEL> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (velocity
    :reader velocity
    :initarg :velocity
    :type adis_16480_driver-msg:Velocity
    :initform (cl:make-instance 'adis_16480_driver-msg:Velocity))
   (ypr
    :reader ypr
    :initarg :ypr
    :type adis_16480_driver-msg:YPR
    :initform (cl:make-instance 'adis_16480_driver-msg:YPR)))
)

(cl:defclass HR_YPR_lVEL (<HR_YPR_lVEL>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HR_YPR_lVEL>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HR_YPR_lVEL)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name adis_16480_driver-msg:<HR_YPR_lVEL> is deprecated: use adis_16480_driver-msg:HR_YPR_lVEL instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <HR_YPR_lVEL>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-msg:header-val is deprecated.  Use adis_16480_driver-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <HR_YPR_lVEL>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-msg:velocity-val is deprecated.  Use adis_16480_driver-msg:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'ypr-val :lambda-list '(m))
(cl:defmethod ypr-val ((m <HR_YPR_lVEL>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader adis_16480_driver-msg:ypr-val is deprecated.  Use adis_16480_driver-msg:ypr instead.")
  (ypr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HR_YPR_lVEL>) ostream)
  "Serializes a message object of type '<HR_YPR_lVEL>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'velocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ypr) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HR_YPR_lVEL>) istream)
  "Deserializes a message object of type '<HR_YPR_lVEL>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'velocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ypr) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HR_YPR_lVEL>)))
  "Returns string type for a message object of type '<HR_YPR_lVEL>"
  "adis_16480_driver/HR_YPR_lVEL")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HR_YPR_lVEL)))
  "Returns string type for a message object of type 'HR_YPR_lVEL"
  "adis_16480_driver/HR_YPR_lVEL")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HR_YPR_lVEL>)))
  "Returns md5sum for a message object of type '<HR_YPR_lVEL>"
  "3017e4708f9ed9d07542f099ccb02d8e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HR_YPR_lVEL)))
  "Returns md5sum for a message object of type 'HR_YPR_lVEL"
  "3017e4708f9ed9d07542f099ccb02d8e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HR_YPR_lVEL>)))
  "Returns full string definition for message of type '<HR_YPR_lVEL>"
  (cl:format cl:nil "Header header~%Velocity velocity~%YPR ypr~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: adis_16480_driver/Velocity~%int64 linear_x~%int64 linear_y~%int64 linear_z~%================================================================================~%MSG: adis_16480_driver/YPR~%float64 yaw~%float64 pitch~%float64 roll~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HR_YPR_lVEL)))
  "Returns full string definition for message of type 'HR_YPR_lVEL"
  (cl:format cl:nil "Header header~%Velocity velocity~%YPR ypr~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: adis_16480_driver/Velocity~%int64 linear_x~%int64 linear_y~%int64 linear_z~%================================================================================~%MSG: adis_16480_driver/YPR~%float64 yaw~%float64 pitch~%float64 roll~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HR_YPR_lVEL>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'velocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ypr))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HR_YPR_lVEL>))
  "Converts a ROS message object to a list"
  (cl:list 'HR_YPR_lVEL
    (cl:cons ':header (header msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':ypr (ypr msg))
))
