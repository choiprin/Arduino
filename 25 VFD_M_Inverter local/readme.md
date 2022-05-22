# [Delta] VFD_M Node-red 제어
![Node_red+VFD인버터-001](https://user-images.githubusercontent.com/98401825/169675708-6d1cb506-64f2-4d93-bf37-2416500f19f0.png)

### Node-red function노드로 제어  
* Node 구성도  
![image](https://user-images.githubusercontent.com/98401825/169675735-66160a4e-4c1c-4747-beab-e289469d06d9.png)

  
* 메뉴얼 참고해서 RS485관련 파라미터 설정 필요
* 메뉴얼 링크 : <http://dycop.com/pdf/delta-vfd-m-manual.pdf>  

### VFD_M 인버터 프로토콜 분석
![VFD_M인버터 메뉴얼캡쳐2](https://user-images.githubusercontent.com/98401825/169675388-3ef54554-b947-47bd-85b6-9bf567046d9a.jpg)
  
* 정회전 : FWD RUN 이므로 2000번지의 0001 0010 = 18(DEC) = 0x12(HEX)  
* 역회전 : REV RUN 이므로 2000번지의 0010 0010 = 34(DEC) = 0x22(HEX)    
* 정지 : 기능없음 STOP 이므로 2000번지의 0000 0001 = 1(DEC) = 0x01(HEX)  


