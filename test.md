# 소스정리
    # "리소스 타입" "리소스 네이밍"
    resource "aws_key_pair" "web_admin" {
      key_name = "web_admin"
      # 만든 ssh 키
      public_key = file("~/.ssh/web_admin.pub")
    }




