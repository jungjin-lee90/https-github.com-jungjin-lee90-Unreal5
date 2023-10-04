# 소스정리
    # provider 즉 어떤 클라우드 서비스를 사용할 건지
    provider "aws" {  
        # 발급 받은 Access Key
        access_key = "<AWS_ACCESS_KEY>"
        # 발급 받은 Secrey Key
        secret_key = "<AWS_SECRET_KEY>"
        # 어느 나라 인지
        region = "ap-northeast-2"
    }
    # 어떤 버전을 사용할건지에 대한 정의    
    terraform {
      required_version = "1.5.7"
    
      required_providers {
        aws = ">= 5.17.0"
      }
    }


