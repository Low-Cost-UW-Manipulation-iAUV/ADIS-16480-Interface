
(cl:in-package :asdf)

(defsystem "adis_16480_driver-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "HR_YPR_lVEL" :depends-on ("_package_HR_YPR_lVEL"))
    (:file "_package_HR_YPR_lVEL" :depends-on ("_package"))
    (:file "Quaternion" :depends-on ("_package_Quaternion"))
    (:file "_package_Quaternion" :depends-on ("_package"))
    (:file "HR_YPR_lACC" :depends-on ("_package_HR_YPR_lACC"))
    (:file "_package_HR_YPR_lACC" :depends-on ("_package"))
    (:file "Velocity" :depends-on ("_package_Velocity"))
    (:file "_package_Velocity" :depends-on ("_package"))
    (:file "LR_YPR" :depends-on ("_package_LR_YPR"))
    (:file "_package_LR_YPR" :depends-on ("_package"))
    (:file "YPR" :depends-on ("_package_YPR"))
    (:file "_package_YPR" :depends-on ("_package"))
    (:file "Acceleration" :depends-on ("_package_Acceleration"))
    (:file "_package_Acceleration" :depends-on ("_package"))
  ))