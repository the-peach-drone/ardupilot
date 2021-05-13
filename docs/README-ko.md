[![thepeach logo](http://gabom1.pagei.gethompy.com/data/editor/2005/ae065791211b1de95f89a5c5c9f796b7_1589185049_9675.png)](http://thepeach.kr)



## 우분투에서 빌드환경 설정

* 리포지토리 clone 및 필요한 패키지 설치

```bash
$ sudo apt-get update

$ sudo apt-get install git

$ git clone https://github.com/ThePeach-Drone/ardupilot.git

$ cd ardupilot

$ git submodule update --init --recursive

$ Tools/environment_install/install-prereqs-ubuntu.sh -y

$ . ~/.profile
```


  * 검색 경로에 일부 폴더 추가

    -- 파일 앞에 붙어있는 .에 유의하세요. 숨긴 파일을 의미하므로 파일 관리자를 사용할 경우 "숨김 파일 표시"를 켜야합니다.

```ba
cd ~
vim .bashrc
```

*  home/user 폴더안에 .bashrc파일 끝에 다음 행을 추가.

  ```bash
  export PATH=$PATH:$HOME/ardupilot/Tools/autotest
  export PATH=/usr/lib/ccache:$PATH
  ```
​	  

* 그런 다음 터미널에서 "."명령어을 사용하여 PATH를 로드한다.

```bash
$ . ~/.bashrc

$ sudo usermod -a -G dialout $USER
```



## THE PEACH K1 Board

![THEPEACH K1](../libraries/AP_HAL_ChibiOS/hwdef/thepeach-k1/THEPEACH_K1.png)
 * THE PEACH K1 firmware를 빌드하는 방법
```bash
$ ./waf clean

$ ./waf configure --board thepeach-k1

$ ./waf copter
```
-- "arducopter" 바이너리 파일은 build/thepeach-k1/bin 폴더에 생성된다.



## THE PEACH R1 Board

![THEPEACH R1](../libraries/AP_HAL_ChibiOS/hwdef/thepeach-r1/THEPEACH_R1.png)
 * THE PEACH R1 firmware를 빌드하는 방법
```bash
$ ./waf clean

$ ./waf configure --board thepeach-r1

$ ./waf copter
```
-- "arducopter" 바이너리 파일은 build/thepeach-r1/bin 폴더에 생성된다.