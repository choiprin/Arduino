## Google Home 관련 설정 
### *Action google*  
***
1. [Actions on Google Console](https://console.actions.google.com/ "Action Google")
로 이동
2. 새 프로젝트를 생성( 언어 - Korean, 지역 - South Korea )
3. 6개 항목 중에서 Smart Home 선택 후 start building 버튼 클릭
4. Quick setup 란에서 'Name your Smart Home action' 클릭
5. __Develop) Invocation__ 에서 Display Name 입력( Google Home 앱에 등록될 이름 )
6. __Develop) Actions__ 에서 Fullfilment URL을 입력
    https://us-central1-<project-id\>.cloudfunctions.net/smarthome  
    ( project-id 에 현재 프로젝트 id 입력 ex)https://us-central1-test-12345.cloudfunctions.net/smarthome )
7. __Develop) Account linking__ 에서 다음과 같이 입력     
Client ID               : ABC123    
Client secret           : DEF456    
    Authorization URL       : https://us-central1-<project-id\>.cloudfunctions.net/fakeauth      
    Token URL               : https://us-central1-<project-id\>.cloudfunctions.net/faketoken  
    테스트 용도기 때문에 default 값들을 사용함  
### *Google Cloud Platform*  
***
8. [Google 클라우드 플랫폼](https://console.cloud.google.com/)으로 이동  
9. "__Google Cloud Platform__"에서 생성했던 프로젝트를 선택
10. "__APIs & Services > Library__" 에서 "HomeGraph API"을 검색 후 설치( enable )      
"__APIs & Services > Credentials__" 에서 Create Credentials 버튼 클릭, Service account 클릭 
10. 임의로 이름을 지정 후 생성된 Service Accounts 찾아서 클릭  
11. __Keys > Add Key > Create New Key > JSON__ JSON키 생성 
12. 다운받은 JSON키 파일 이름을 "smart-home-key.json"로 변경
 
### *Firebase Deploy*
***
1. 현재 github에 업로드 되어있는 폴더를 다운  
2. 각자 저장한 경로에 맞게 Google Smart Home/firebase/functions 로 이동 후 cmd 실행  
3. 다음을 순서대로 실행  
```
npm install -g firebase-tools  
npm install  
firebase login  
firebase projects:list  
```
위 명령어까지 실행하면 리스트들이 나옴. 원하는 리스트를 확인 후  
```
firebase use project-id  
```
__project-id 대신 해당하는 id 입력__  
프로젝트가 활성화 됐는지 확인하려면  
```
firebase projects:list  
```
위 명령어를 한 번 더 실행. 활성화된 프로젝트의 색이 변함  
```
firebase deploy
```
deploy단계에서 에러가 발생하면 해당 디렉토리의 package.json Node버전을 10으로 변경  
```
  "engines": {
    "node": "10"
  }
```
***
Google Home Document  :  https://developers.google.cn/assistant/smarthome/overview
