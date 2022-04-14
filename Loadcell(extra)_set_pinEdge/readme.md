# ESP8266
![Loadcell+스위치배선도](https://user-images.githubusercontent.com/98401825/163318778-cfcc0381-c884-4272-9fb2-ba8789e92032.png)  

### 채터링 현상  
* 스위치를 누르다 보면, 신호의 상태가 변할 때마다  
0(Low)도 1(HIGH)도 아닌 상태가 발견됨 - 채터링[chattering]  
![채터링현상](https://user-images.githubusercontent.com/98401825/163317025-1207b847-866e-4ef9-a2e9-991e00a8d980.png)
  
* 이를 방지하기 위해 pinMode(D2, INPUT_PULLUP); 선언 및 소프트웨어로 해결
 

