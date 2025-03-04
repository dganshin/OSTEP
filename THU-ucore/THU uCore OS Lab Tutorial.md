# THU uCore OS Lab Tutorial

## 注意事项
### Lab1
#### 练习2
在执行
```bash
make lab1-mon
```
之后报错:
```bash
# Option “-e” is deprecated and might be removed in a later version of gnome-terminal.
# Use “-- ” to terminate the options and put the command line to execute after it.
```
只需要进入os_kernel_lab/labcodes_answer/lab1_result/, 打开Makefile, 把所有单独的 **-e**参数替换为**--**即可(区分大小写哦)

同时还可能会报错
```bash
# Failed to parse arguments: Cannot open display: 
make: *** [Makefile:202: lab1-mon] Error 1
```
可能是因为远程服务器没有图形化界面, 但是qemu需要图形化界面, 所以无法正常启动qemu
