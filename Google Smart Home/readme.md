## 스마트홈 (Google Actio Smart Home) 만들기    
### Action Google과 Google Cloud 설정  
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
### Google Cloud Platform  
8. [Google 클라우드 플랫폼](https://console.cloud.google.com/)으로 이동  
9. "__Google Cloud Platform__"에서 생성했던 프로젝트를 선택
10. "__APIs & Services > Library__" 에서 "HomeGraph API"을 검색 후 설치( enable )      
"__APIs & Services > Credentials__" 에서 Create Credentials 버튼 클릭, Service account 클릭 
10. 임의로 이름을 지정 후 생성된 Service Accounts 찾아서 클릭  
11. __Keys > Add Key > Create New Key > JSON__ JSON키 생성 
12. 다운받은 JSON키 파일 이름을 "smart-home-key.json"을 바꾼다.
 
### 제어프로그램 작성과 업로드
1. 참조사이트 https://github.com/shivasiddharth/google-actions-smarthome 에서 "Code"를 선택해 소스프로그램을 내려받고 압축을 푼다.
2. 다음 디렉토리로 이동 google-actions-smarthome-master\smarthome-control\functions 
3. console창에서 다음을 순서대로 실행한다.      
firebase login      
firebase use \<project-id\>       
npm install     
firebase deploy
*** npm과 firebse가 실행되지 않으면 이를 설치하세요 https://www.youtube.com/watch?v=uBZ78C--T6U

4. 다음 URL로 접속한다.     
https://us-central1-\<project-id\>.cloudfunctions.net/smarthome
5. Google Home을 시작한다.


Google Smart Home 문서 : 기기들 상세 프로그램을 하려면 참조하세요 https://developers.google.cn/assistant/smarthome/overview

참조유튜브 : https://www.youtube.com/watch?v=e1C5WIfZ89s
