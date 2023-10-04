# 소스정리
    # provider 즉 어떤 클라우드 서비스를 사용할 건지
    provider "aws" {  

    }
    # 어떤 버전을 사용할건지에 대한 정의    
    terraform {
      required_version = "1.5.7"
    
      required_providers {
        aws = ">= 5.17.0"
      }
    }


