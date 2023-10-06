# 소스정리
    resource "aws_key_pair" "web_admin" {
      key_name = "web_admin"
      public_key = file("~/.ssh/web_admin.pub")
    }
    
    resource "aws_security_group" "ssh" {
      name = "allow_ssh_from_all"
      description = "Allow SSH port from all"
      ingress {
        from_port = 22
        to_port = 22
        protocol = "tcp"
        cidr_blocks = ["0.0.0.0/0"]
      }
    }
    
    # resource가 아니고 data이다. 
    # 이름이 default인 sercuroty_group을 찾아서 값을 참조할 수 있게 해준다.
    data "aws_security_group" "default" {
      name = "default"
      # 만약 default라는 이름이 중복되면
      # 아래와 같이 ID를 넣어 구분해줘야 한다.
      id = "<SECURITY_GROUP_ID>" 
    }
    # 인스턴스 web을 만든다.
    resource "aws_instance" "web" {
      # ami는 현재 최신 버전의 값을 넣어줬다.
      # Amazon Machine Image = ami
      ami = "ami-0e581dc33f688a5df"
      instance_type = "t2.micro"
      # 위에 추가한 값들을 불러다 쓴다.
      key_name = aws_key_pair.web_admin.key_name
      vpc_security_group_ids = [
        aws_security_group.ssh.id,
        data.aws_security_group.default.id
      ]
    }
    # 위는 이미 추가한 내용, 설명을 위해 추가해둠.
    ############################################################################
    # db resource "web_db" 생성
    resource "aws_db_instance" "web_db" {
      # DB 사이즈, 기가 단위
      allocated_storage = 8 
      # 어떤 sql 쓸건지
      engine = "mysql"
      engine_version = "8.0.33"
      instance_class = "db.t2.micro"
      ## db_name 추가
      db_name = "mysql" 
      username = "admin"
      # password는 임시 비밀번호로 쓸거라 대충 만들고 나중에 DB 접속해서 변경
      password = "11112222"
      # 인스턴스 삭제시 최종 스냅샷 스킵 여부, 디폴트는 false인데 이러면 삭제가 힘들어 true로 변경
      skip_final_snapshot = true
    }




