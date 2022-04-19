# Load-cell, HX711, 근접센서(CR18-8DN) 배선도
![근접센서+Loadcell배선도](https://user-images.githubusercontent.com/98401825/163947656-780d2719-431a-42b6-b0f5-162eb38d7ec0.png)

### 동작설명  
* 제품 특성상 물체를 감지했을 때, 신호출력핀에 전압이 LOW로 변함
* 특정 interrupt( 출력핀의 전압 Low) 이 걸리면, Loadcell의 값을 출력  
* Loadcell이 출력한 횟수를 counter로 출력  

### 시리얼 모니터  
* 하중 없을 시  
![근접센서+Loadcell시리얼모니터](https://user-images.githubusercontent.com/98401825/163946248-726e9855-8e51-45f1-8fc8-cf78a5f9518f.png)  
* 하중 발생 시  
![근접센서+Loadcell시리얼모니터2](https://user-images.githubusercontent.com/98401825/163946353-0b335dbd-8a80-48ca-8095-ff68fd24ba49.png)


 

