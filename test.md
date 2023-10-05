# 소스정리
    # aws_security_group resource를 ssh라고 명명
    resource "aws_security_group" "ssh" {
      name = "allow_ssh_from_all"
      description = "Allow SSH port from all"
      ingress { # 인바운드 설정
        from_port = 22 # 22번 포트부터
        to_port = 22 # 22번 포트까지 사용. ssh는 22번 포트 쓰기에 22번 포트만 사용하게끔 설정
        protocol = "tcp" # 프로토콜은 tcp
        cidr_blocks = ["0.0.0.0/0"] # 모든 IP에서 다 열어주겠다.
      }
    }




