세부과제 1
1) gcc -o isPrimeNumber main.c
2) ./isPrimeNumber 숫자 ex> ./isPrimeNumber 2

세부과제 2
1) chmod +x hw1.sh
2) ./hw1.sh 
    (엔터 후 사용자 입력)
3) 다시 입력할 때마다 파일 안에 내용이 새로 써지도록 하기위해서
   - cat /dev/null > log.txt 라는 함수를 썼습니다. 혹시라도 참고해주세요

세부과제 3 
1) gcc -c  main2.c
  - 코드오류밑에 나와도 main.o 생기는데에는 문제 없습니다. 넘어가주세요
2) gcc -o isPrimeNumber2 main.o libutil.o 
3) ./isPrimeNumber2 숫자 입력
