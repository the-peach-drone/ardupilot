# THE PEACH
[![thepeach logo](http://gabom1.pagei.gethompy.com/data/editor/2005/ae065791211b1de95f89a5c5c9f796b7_1589185049_9675.png)](http://thepeach.kr)

 * Setup the Build Environment on Linux/Ubuntu
```bash
$ sudo apt-get update

$ sudo apt-get install git

$ git clone https://github.com/the-peach-drone/ardupilot.git

$ cd ardupilot

$ git submodule update --init --recursive

$ Tools/environment_install/install-prereqs-ubuntu.sh -y

$ . ~/.profile
```
  * Add some directories to your search path (Facultative)
  -- Add the following lines to the end of your ".bashrc" in your home directory (notice the . on the start of that filename. Also, this is a hidden file, so if you're using a file manager, make sure to turn on "show hidden files").
  ```bash
  export PATH=$PATH:$HOME/ardupilot/Tools/autotest
  export PATH=/usr/lib/ccache:$PATH
  ```
  -- Then reload your PATH by using the "dot" command in a terminal
  ```bash
  $ . ~/.bashrc

  $ sudo usermod -a -G dialout $USER
  ```

## THE PEACH K1 Board
![THEPEACH K1](./libraries/AP_HAL_ChibiOS/hwdef/thepeach-k1/THEPEACH_K1.png)
 * How to build THE PEACH K1's firmware
```bash
$ ./waf clean

$ ./waf configure --board thepeach-k1

$ ./waf copter

```
-- The "arducopter" binaries should appear in the build/thepeach-k1/bin directory.


## THE PEACH R1 Board
![THEPEACH R1](./libraries/AP_HAL_ChibiOS/hwdef/thepeach-r1/THEPEACH_R1.png)
 * How to build THE PEACH R1's firmware
```bash
$ ./waf clean

$ ./waf configure --board thepeach-r1

$ ./waf copter

```
-- The "arducopter" binaries should appear in the build/thepeach-r1/bin directory
