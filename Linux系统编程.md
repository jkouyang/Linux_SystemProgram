# 1. 基础知识

## 1.1 目录结构

在早期的 UNIX 系统中，各个厂家各自定义了自己的 UNIX 系统文件目录，比较混乱。Linux 面世不久后，对文件目录进行了标准化，于1994年对根文件目录做了统一的规范，推出 FHS ( Filesystem Hierarchy Standard ) 的 Linux 文件系统层次结构标准。FHS 标准规定了 Linux 根目录各文件夹的名称及作用，统一了Linux界命名混乱的局面。

和Windows操作系统类似，所有Unix/Linux的数据都是由文件系统按照树型目录结构管理的。而且Unix/Linux操作系统同样要区分文件的类型，判断文件的存取属性和可执行属性。

Unix/Linux也采用了树状结构的文件系统，它由目录和目录下的文件一起构成。但Unix/Linux文件系统不使用驱动器这个概念，而是使用单一的根目录结构，所有的分区都挂载到单一的“/”目录上，其结构示意图如图所示：

<img src="img\linux目录树状图.png" alt="linux目录树状图" style="zoom:67%;" />

无论何种版本的 Linux 发行版，桌面、应用是 Linux 的外衣，文件组织、目录结构才是Linux的内心

### Linux常见目录介绍(熟悉)

- **/：**根目录，一般根目录下只存放目录，在Linux下有且只有一个根目录。所有的东西都是从这里开始。当你在终端里输入“/home”，你其实是在告诉电脑，先从/（根目录）开始，再进入到home目录
- **/bin:** **/usr/bin:** 可执行二进制文件的目录，如常用的命令ls、tar、mv、cat等
- **/boot：**放置linux系统启动时用到的一些文件，如Linux的内核文件：/boot/vmlinuz，系统引导管理器：/boot/grub
- **/dev：**存放linux系统下的设备文件，访问该目录下某个文件，相当于访问某个设备，常用的是挂载光驱 mount /dev/cdrom /mnt
- **/etc**：系统配置文件存放的目录，不建议在此目录下存放可执行文件
- **/home：**系统默认的用户家目录，新增用户账号时，用户的家目录都存放在此目录下
- **/lib: /usr/lib: /usr/local/lib**系统使用的函数库的目录，程序在执行过程中，需要调用一些额外的参数时需要函数库的协助。
- **/lost+fount：**系统异常产生错误时，会将一些遗失的片段放置于此目录下
- **/mnt:/media：**光盘默认挂载点，通常光盘挂载于 /mnt/cdrom 下，也不一定，可以选择任意位置进行挂载
- **/opt：**给主机额外安装软件所摆放的目录
- **/proc**：此目录的数据都在内存中，如系统核心，外部设备，网络状态，由于数据都存放于内存中，所以不占用磁盘空间，比较重要的目录有 /proc/cpuinfo、/proc/interrupts、/proc/dma、/proc/ioports、/proc/net/* 等
- **/root：**系统管理员root的家目录
- **/sbin:/usr/sbin:/usr/local/sbin：**放置系统管理员使用的可执行命令，如fdisk、shutdown、mount 等。与 /bin 不同的是，这几个目录是给系统管理员 root使用的命令，一般用户只能"查看"而不能设置和使用
- **/tmp：**一般用户或正在执行的程序临时存放文件的目录，任何人都可以访问，重要数据不可放置在此目录下。
- **/srv：**服务启动之后需要访问的数据目录，如 www 服务需要访问的网页数据存放在 /srv/www 内。
- **/usr**：应用程序存放目录，/usr/bin 存放应用程序，/usr/share 存放共享数据，/usr/lib 存放不能直接运行的，却是许多程序运行所必需的一些函数库文件。/usr/local: 存放软件升级包。/usr/share/doc: 系统说明文件存放目录。/usr/share/man: 程序说明文件存放目录。
- **/var：**放置系统执行过程中经常变化的文件，如随时更改的日志文件 /var/log，/var/log/message：所有的登录文件存放目录，/var/spool/mail：邮件存放的目录，/var/run:程序或服务启动后，其PID存放在该目录下。

## 1.2. Linux命令解析器

### shell命令解释器

命令解析器的作用：交互式地解释、执行用户输入的命令，将用户的操作翻译成机器可以识别的语言，完成相应功能。

<img src="img\Bash解析器.png" alt="Bash解析器" style="zoom:67%;" />

Linux系统中提供了好几种不同的命令解释器，如shell(/bin/sh)、bash(/bin/bash)等，一般默认使用bash作为默认的解释器。

### Bash解析器常用快捷键(熟练)

**Tab键**

- 补齐命令
- 补齐路径
- 显示当前目录下的所有目录

**清屏 Ctrl + L**

**中断进程 Ctlr+c**

**遍历输入的历史命令**

- 从当前位置向上遍历：ctrl + p （**↑**）
- 从当前位置向下遍历： ctrl + n（**↓**）

**光标相关操作**

- 光标左移： ctrl + b （**←**）
- 坐标右移： ctrl + f （**→**）
- 移动到头部： ctrl + a（**Home**）
- 移动到尾部： ctlr + e（**End**）

**字符删除**

- 删除光标前边的字符：ctrl + h（**Backspace**）

- 删除光标后边的字符：ctrl + d

  光标后边的字符即光标覆盖的字符

- 删除光标前所有内容：ctrl + u

- 删除光标后所有内容：ctrl + k

## 1.3 Linux命令

### 内建命令和外部命令

**内建命令**

shel内建命令是指bash（或其它版本）工具中集成的命令，是否是自带的

**外部命令**

外部命令是安装外部软件所带的命令

**命令类型查看方法**

使用type命令查看：

type [-afptP] 名称 [名称 ...] 显示命令类型的信息。

> type  cd

### Linux命令格式(掌握)

**command [ -options] [parameter1] …**

**说明:**

- command：命令名，相应功能的英文单词或单词的缩写
- [-options]：选项，可用来对命令进行控制，也可以省略，[]代表可选
- parameter1 …：传给命令的参数，可以是零个一个或多个

![linux命令格式](img\linux命令格式.png)

## 1.4 帮助文档查看方法

### man

man 是 Linux 提供的一个手册，包含了绝大部分的命令、函数使用说明。

该手册分成很多章节（section），使用 man 时可以指定不同的章节来浏览不同的内容。

**man** **中各个** **section** **意义如下：**

- 章节1)．Standard commands（标准命令）
- 章节2)．System calls（系统调用，如open,write）
- 章节3)．Library functions（库函数，如printf,fopen）
- 章节4)．Special devices（设备文件的说明，/dev下各种设备）
- 章节5)．File formats（文件格式，如passwd）
- 章节6)．Games and toys（游戏和娱乐）
- 章节7)．Miscellaneous（杂项、惯例与协定等，例如Linux档案系统、网络协定、ASCII 码；environ全局变量）
- 章节8)．Administrative Commands（管理员命令，如ifconfig）

**man使用格式如下：**

man [选项] 命令名

使用 man 手册时，最好指定章节号

> man socket //查看socket()函数，从第一章开始
>
> man 3 bind //查看第3章节bind()函数

**man设置了如下的功能键:**

| **功能键** | **功能**             |
| :--------- | :------------------- |
| 空格键     | 显示手册页的下一屏   |
| Enter键    | 一次滚动手册页的一行 |
| b          | 回滚一屏             |
| f          | 前滚一屏             |
| q          | 退出man命令          |
| h          | 列出所有功能键       |
| **/word**  | **搜索word字符串**   |

### 内建命令(help)

> help 内建命令

### 外部命令(--help)

> 内建命令 --help

一般是 Linux 命令自带的帮助信息，并不是所有命令都自带这个选项

## 1.5 目录相关的命令

### pwd

使用pwd命令可以显示当前的工作目录，该命令很简单，直接输入pwd即可，后面不带参数。

> pwd

### cd

在使用Unix/Linux的时候，经常需要更换工作目录。cd命令可以帮助用户切换工作目录。Linux所有的目录和文件名大小写敏感。

cd后面可跟绝对路径，也可以跟相对路径。如果省略目录，则默认切换到当前用户的主目录。

| **命令** | **含义**                                                     |
| :------- | :----------------------------------------------------------- |
| cd       | 切换到当前用户的主目录(/home/用户目录)，用户登陆的时候，默认的目录就是用户的主目录。 |
| cd ~     | 切换到当前用户的主目录(/home/用户目录)                       |
| cd .     | 切换到当前目录                                               |
| cd ..    | 切换到上级目录                                               |
| cd -     | 可进入上一个进入的目录                                       |

### mkdir

用法：mkdir [选项]... 目录...**创建空目录**

> mkdir 目录名

### rmdir

用法：rmdir [选项]... 目录... **删除指定的空目录**

可使用rmdir命令删除一个目录。必须离开目录，并且目录必须为空目录，不然提示删除失败。

## 1.6 文件相关命令

### 文件类型

**Linux下一切皆文件**，Unix/Linux系统中常用的文件类型有7种：普通文件、目录文件、设备文件、管道文件、链接文件和套接字。

![文件类型](img\文件类型.jpg)



### ls

ls是英文单词list的简写，其功能为列出目录的内容，是用户最常用的命令之一，它类似于DOS下的dir命令。

**用法：ls [选项] 文件名** 

加文件名就显示具体文件名的信息，不加就显示该目录下的文件信息

| **参数** | **含义**                                     |
| :------- | :------------------------------------------- |
| -a       | 显示指定目录下所有子目录与文件，包括隐藏文件 |
| -l       | 以列表方式显示文件的详细信息                 |
| -h       | 配合 -l 以人性化的方式显示文件大小           |

### touch

**用法：touch [选项] 文件名**

1）如果文件不存在, 创建新文件(只能是普通文件，不能是文件夹)

2）如果文件存在, 更新文件时间

### cp

cp命令的功能是将给出的文件或目录复制到另一个文件或目录中，相当于DOS下的copy命令 

> cp file newfile //在当前目录下将file以newfile名复制一份
>
> cp file  ../ver4 //在../ver4目录下将file复制一份
>
> cp -rf folder1 folder2//将整个文件夹拷贝一份

常用选项说明：

| 选项 | 含义                                                         |
| :--- | :----------------------------------------------------------- |
| -a   | 该选项通常在复制目录时使用，它保留链接、文件属性，并递归地复制目录，简单而言，保持文件原有属性。 |
| -f   | 删除已经存在的目标文件而不提示                               |
| -i   | 交互式复制，在覆盖目标文件之前将给出提示要求用户确认         |
| -r   | 若给出的源文件是目录文件，则cp将递归复制该目录下的所有子目录和文件，目标文件必须为一个目录名。 |
| -v   | 显示拷贝进度                                                 |

### rm

可通过**rm删除文件或目录**。使用rm命令要小心，因为文件删除后不能恢复。为了防止文件误删，可以在rm后使用-i参数以逐个确认要删除的文件。

| **参数** | **含义**                                         |
| :------- | :----------------------------------------------- |
| -i       | 以进行交互式方式执行                             |
| -f       | 强制删除，忽略不存在的文件，无需提示             |
| -r       | 递归地删除目录下的内容，删除文件夹时必须加此参数 |

### mv

用户可以使用mv命令来移动文件或目录，也可以给文件或目录重命名。

> mv file1 file2 //把file1文件重命名为file2
>
> mv file  ../ver4 //把file文件移动到../ver4目录下

| **选项** | **含义**                                                     |
| :------- | :----------------------------------------------------------- |
| -f       | 禁止交互式操作，如有覆盖也不会给出提示                       |
| -i       | 确认交互方式操作，如果mv操作将导致对已存在的目标文件的覆盖，系统会询问是否重写，要求用户回答以避免误覆盖文件 |
| -v       | 显示移动进度                                                 |

### cat

> cat 文件名

cat 将文件内容一次性输出到终端。

缺点：终端显示的内容有限，如果文件太长无法全部显示。

### more(了解)

more命令将文件内容分页显示到终端，但是只能一直向下浏览，不能回退：

> more 文件名

相关说明：

| **命令**      | **作用**   |
| :------------ | :--------- |
| 回车          | 显示下一行 |
| 空格          | 显示下一页 |
| q（ctrl + c） | 退出       |
| h             | 获取帮助   |

### less

less命令将文件内容分页显示到终端，可以自由上下浏览

> lsee 文件名

| **命令**       | **作用**   |
| :------------- | :--------- |
| 回车(ctrl + n) | 显示下一行 |
| ctrl + p       | 显示上一行 |
| 空格(PageDown) | 显示下一页 |
| PageUp         | 显示上一页 |
| q              | 退出       |
| h              | 获取帮助   |

### head

- head命令从文件头部开始查看前 n 行的内容。
- 如果没有指定行数，默认显示前10行内容。

> head –n[行数] 文件名

### tail

- 从文件尾部向上查看最后 n 行的内容
- 使用方式：tail –n[行数] 文件名
- 如果没有指定行数，默认显示最后10行内容

> tail –n[行数] 文件名

### ln

ln命令主要用于创建链接文件。Linux链接文件类似于Windows下的快捷方式。

链接文件分为软链接和硬链接：

- 软链接：软链接不占用磁盘空间，源文件删除则软链接失效。
- 硬链接：硬链接只能链接普通文件，不能链接目录。

使用格式：

ln 源文件 链接文件

ln -s 源文件 链接文件

如果没有-s选项代表建立一个硬链接文件，两个文件占用相同大小的硬盘空间，即使删除了源文件，链接文件还是存在，所以-s选项是更常见的形式。

## 1.7 容量查询

### du

du命令用于**查看某个目录或文件大小**

du命令的使用格式如下：

du [选项] 目录或文件名

| **选项** | **含义**                                           |
| :------- | :------------------------------------------------- |
| -a       | 递归显示指定目录中各文件和子目录中文件占用的数据块 |
| -s       | 显示指定文件或目录占用的数据块                     |
| -b       | 以字节为单位显示磁盘占用情况                       |
| -h       | 以K，M，G为单位，提高信息的可读性                  |

### df

df命令**用于检测文件系统的磁盘空间占用和空余情况**，可以显示所有文件系统对节点和磁盘块的使用情况。

| **选项** | **含义**                          |
| :------- | :-------------------------------- |
| -a       | 显示所有文件系统的磁盘使用情况    |
| -m       | 以1024字节为单位显示              |
| -h       | 以K，M，G为单位，提高信息的可读性 |

## 1.8 查找相关命令(重点)

### find

**find命令功能非常强大，通常用来在特定的目录下搜索符合条件的文件**，也可以用来搜索特定用户属主的文件。

- **按文件名查询：使用参数 -name**

命令：find + 路径 + -name +“文件名”    //文件名可配合正则表达式使用

> find /home -name “a.txt”

- **按文件大小查询：使用参数 -size**

命令：find + 路径 + -size + 范围(+表示大于，-表示小于)

> find -size +10k

**按文件类型查询：使用参数 -type**

命令：find + 路径 + -type + 类型

> find -type h

 普通文件类型用 **f** 表示而不是-

d -> 目录

 l -> 符号链接

b -> 块设备文件

c -> 字符设备文件

s -> socket文件，网络套接字

p -> 管道

### grep

grep命令是一种强大的文本搜索工具，grep允许对文本文件进行模式查找。如果找到匹配模式， grep打印包含模式的所有行。

**grep [-选项] ‘搜索内容串’ 文件名**

> grep 'include' server.cpp

| **选项** | **含义**                                 |
| :------- | :--------------------------------------- |
| -v       | 显示不包含匹配文本的所有行（相当于求反） |
| -n       | 显示匹配行及行号                         |
| -i       | 忽略大小写                               |

## 1.9 管道

管道(|)：一个命令的输出可以通过管道做为另一个命令的输入

command1 | command2  command1将其输出作为command2的输入

> netstat -a\|grep 5188  //查看所有端口信息 | 里面包含5188的行，即查询端口5188的信息

## 1.10 压缩包管理(重点)

### tar

计算机中的数据经常需要备份，tar是Unix/Linux中最常用的备份工具，此命令可以把一系列文件归档到一个大文件中，也可以把档案文件解开以恢复数据。

tar使用格式

> tar [选项] 打包文件名 文件

tar命令很特殊，其选项前面可以使用“-”，也可以不使用。

常用参数：

| **参数** | **含义**                                                  |
| :------- | :-------------------------------------------------------- |
| -c       | 生成档案文件，创建打包文件                                |
| -v       | 列出归档解档的详细过程，显示进度                          |
| -f       | 指定档案文件名称，f后面一定是.tar文件，所以必须放选项最后 |
| -t       | 列出档案中包含的文件                                      |
| -x       | 解开档案文件                                              |

注意：除了f需要放在参数的最后，其它参数的顺序任意。

### gzip

l tar与gzip命令结合使用实现文件打包、压缩。

l tar只负责打包文件，但不压缩，用gzip压缩tar打包后的文件，其扩展名一般用xxxx.tar.gz。

> gzip [选项] 被压缩文件

| **选项** | **含义**       |
| :------- | :------------- |
| -d       | 解压           |
| -r       | 压缩所有子目录 |

一次性压缩多个文件: gzip后面不能跟目录

## 1.11 重定向

标准输入 代码 0 默认设备为键盘
​标准输出 代码 1 默认设备为屏幕
​错误输出 代码 2 默认设备为屏幕

> \> 标准正确输出重定向(覆盖)
>
> \>> 标准正确输出重定向(追加)
>
> 2\> 标准错误输出重定向(覆盖)
>
> 2\>> 标准错误输出重定向(追加)
>
> &> 标准正确、标准错误输出重定向(覆盖)
>
> &>> 标准正确、标准错误输出重定向(追加)

ls /etc/passwd > output.txt 标准正确输出重定向到output.txt

ls /etc/shadow >> output.txt 标准正确输出追加重定向到output.txt

ls dddddd 2> error.txt 标准错误输出重定向到error.txt

ls ddddd 2>> error.txt 标准错误输出重定向到error.txt,追加的方式

ls dddddd 2> /dev/null 标准错误输出重定向到黑洞

ls ddddd /etc/passwd &> /dev/null 标准正确输出标准错误输出全都重定向到黑洞

ls ddddd /etc/passwd &>> txt 标准正确输出标准错误输出以追加的方式全都重定向到txt

# 2. 编辑、编译、调试（重点）

## 2.1 vim三种模式

vi -> vim

vi有三种基本工作模式: **命令模式、文本输入模式(编辑模式)、末行模式**。

<img src="img\vim_三种模式.jpg" alt="vim_三种模式" style="zoom: 67%;" />

### 命令模式

不管用户处于何种模式,只要按一下**ESC键**,即可使vi进入命令模式。在shell环境(提示符为$)下输入启动vim命令，进入编辑器时，也是处于该模式下。

### 编辑模式

在命令模式下输入**插入命令i（I）**、附加命令a（A） 、打开命令o（O）、替换命s（S）都可以进入文本输入模式，此时vi窗口的最后一行会显示“插入”。

### 末行模式

在命令模式下**输入 : 进入末行模式下**，用户可以对文件进行一些附加处理。尽管命令模式下的命令可以完成很多功能，但要执行一些如字符串查找、替换、显示行号等操作还是必须要进入末行模式的。用户输入完成后，按回车执行，之后vi编辑器又自动返回到命令模式下。

## 2.2 vim基本操作

- 打开或新建文件：**vim filename**
- 保存退出当前文件：命令模式下：(小写状态)，**shift + zz**，或者（大写状态：**ZZ**）

### 命令模式下的操作

**1）切换到编辑模式**

| 按键    | 功能                                   |
| :------ | :------------------------------------- |
| i       | 光标位置当前处插入文字                 |
| I       | 光标所在行首插入文字                   |
| o(字母) | 光标下一行插入文字（新行）             |
| O(字母) | 光标上一行插入文字（新行）             |
| a       | 光标位置右边插入文字                   |
| A       | 光标所在行尾插入文字                   |
| s       | 删除光标后边的字符，从光标当前位置插入 |
| S       | 删除光标所在当前行，从行首插入         |

**2) 光标移动**

| **按键** | **功能**                             |
| :------- | :----------------------------------- |
| Ctrl + f | 向前滚动一个屏幕                     |
| Ctrl + b | 向后滚动一个屏幕                     |
| gg       | 到文件第一行行首                     |
| G(大写)  | 到文件最后一行行首，G必须为大写      |
| mG或mgg  | 到指定行，m为目标行数                |
| 0(数字)  | 光标移到到行首（第一个字符位置）     |
| $        | 光标移到到行尾                       |
| l(小写L) | 向右移动光标                         |
| h        | 向左移动光标                         |
| k        | 向上移动光标                         |
| j        | 向下移动光标                         |
| ^        | 光标移到到行首（第一个有效字符位置） |

**3）复制粘贴**

| **按键** | **功能**                     |
| :------- | :--------------------------- |
| [n]yy    | 复制从当前行开始的 n 行      |
| p        | 把粘贴板上的内容插入到当前行 |

**4）删除**

| **按键**    | **功能**                                                     |
| :---------- | :----------------------------------------------------------- |
| [n]x        | 删除光标后 n 个字符                                          |
| [n]X        | 删除光标前 n 个字符                                          |
| D           | 删除光标所在开始到此行尾的字符                               |
| [n]dd       | 删除从当前行开始的 n 行（准确来讲，是剪切，剪切不粘贴即为删除） |
| dG          | 删除光标所在开始到文件尾的所有字符                           |
| dw          | 删除光标开始位置的字,包含光标所在字符                        |
| d0(0为数字) | 删除光标前本行所有内容,不包含光标所在字符                    |
| dgg         | 删除光标所在开始到文件首行第一个字符开始的所有字符           |

**5）撤销恢复**

| **按键**  | **功能**            |
| :-------- | :------------------ |
| **.**(点) | 执行上一次操作      |
| u         | 撤销前一个命令      |
| ctrl+r    | 反撤销              |
| 100 + .   | 执行上一次操作100次 |

**6）保存退出**

| **按键**      | **功能** |
| :------------ | :------- |
| ZZ(shift+z+z) | 保存退出 |

**7）查找**

| **按键** | **功能**                                   |
| :------- | :----------------------------------------- |
| /字符串  | 从当前光标位置向下查找（n，N查找内容切换） |
| ?字符串  | 从当前光标位置向上查找（n，N查找内容切换） |

**8）替换**

| **按键** | **功能**                                |
| :------- | :-------------------------------------- |
| r        | 替换当前字符                            |
| R        | 替换当前行光标后的字符(ESC退出替换模式) |

**9）可视模式**

| **按键**  | **功能**                                                     |
| :-------- | :----------------------------------------------------------- |
| v         | 按字符移动，选中文本，可配合h、j、k、l选择内容，使用d删除，使用y复制 |
| Shift + v | 行选（以行为单位）选中文本，可配合h、j、k、l选择内容，使用d删除，使用y复制 |
| Ctrl + v  | 列选 选中文本，可配合h、j、k、l选择内容，使用d删除，使用y复制 |

### 末行模式下的操作

**1）保存退出**

| **按键**    | **功能**                                     |
| :---------- | :------------------------------------------- |
| :wq         | 保存退出                                     |
| :x(小写)    | 保存退出                                     |
| :w filename | 保存到指定文件                               |
| :q          | 退出，如果文件修改但没有保存，会提示无法退出 |
| :q!         | 退出，不保存                                 |

**2）替换**

| **按键**         | **功能**                               |
| :--------------- | :------------------------------------- |
| :s/abc/123/      | 光标所在行的第一个abc替换为123         |
| :s/abc/123/g     | 光标所在行的所有abc替换为123           |
| :1,10s/abc/123/g | 将第一行至第10行之间的abc全部替换成123 |
| :%s/abc/123/g    | 当前文件的所有abc替换为123             |
| :%s/abc/123/gc   | 同上，但是每次替换需要用户确认         |
| :1,$s/abc/123/g  | 当前文件的所有abc替换为123             |

**3）分屏**

| **按键**           | **功能**                       |
| :----------------- | :----------------------------- |
| :sp                | 当前文件水平分屏               |
| :vsp               | 当前文件垂直分屏               |
| : sp 文件名        | 当前文件和另一个文件水平分屏   |
| : vsp 文件名       | 当前文件和另一个文件垂直分屏   |
| ctrl-w-w           | 在多个窗口切换光标             |
| :wall/:wqall/:qall | 保存/保存退出/退出所有分屏窗口 |
| vim -O a.c b.c     | 垂直分屏                       |
| vim -o a.c b.c     | 水平分屏                       |

**4) 其它用法(扩展)**

| 按键                         | 功能                                             |
| :--------------------------- | :----------------------------------------------- |
| :!man 3 printf               | 在vim中执行命令 （q退出）                        |
| :r !ls -l                    | 将ls -l执行的结果写入当前文件中                  |
| :r /etc/passwd               | 将/etc/passwd文件中的内容写入到当前文件中        |
| :w /tmp/txt                  | 将当前文件内容写入到/tmp/txt文件中               |
| :w! /tmp/txt                 | 强制将当前文件内容写入到/tmp/txt文件中           |
| :1,10s/^/\/\//g              | 将第1行到10行行首添加// (^表示行首) /\/\转移字符 |
| :1,10s#^#//#g                | 将第1行到10行行首添加// (#可以临时代替/ 分隔)    |
| :%s/;/\r{\r\treturn0;\r}\r/g | 将;替换成{ return 0; }                           |
| :1,10s#//##g                 | 将第1行到10行行首去掉// (#可以临时代替/ 分隔)    |

**5) 配置文件**

后面makefile用

局部配置文件（推荐）

> deng@itcast:~/share/2nd$ vim ~/.vimrc

全局配置文件:

> deng@itcast:~/share/2nd$ sudo vim /etc/vim/vimrc

## 2.3 GCC

gcc原本作为GNU操作系统的官方编译器，现已被大多数类Unix操作系统采纳为标准的编译器，随着项目的发展gcc已经成为了能够编译C、C++、Java、Ada、fortran、Object C、Object C++、Go语言的编译器大家族。

### GCC工作流程

![GCC流程_1](img\GCC流程_1.png)

四个步骤并不是gcc独立完成的，而是在内部调用了其他工具，从而完成了整个工作流程：

![GCC流程_2](C:\Users\ouyang\Desktop\0.linux系统编程知识\img\GCC流程_2.png)

gcc工作的流程

> 第一步: 进行预处理
>
> gcc -E hello.c
>
> 第二步: 生成汇编文件
>
> gcc -S hello.i
>
> 第三步: 生成目标代码
>
> gcc -c hello.s

注意：前三步-E、-S、-c未用-o指定生成得文件名时，会自动根据源文件名匹配

> 第四步: 生成可以执行文件
>
> gcc hello.o -o hello 
>
> 第五步: 执行
>
> ./hello

一步完成，直接将源文件生成一个可以执行文件，如果不指定输出文件名字, gcc编译器会生成一个默认的可以执行a.out

> gcc -c hello.c -o hello

### GG常用选项

| **选项**            | **作用**                                                     |
| :------------------ | :----------------------------------------------------------- |
| -E                  | 只进行预处理                                                 |
| -S(大写)            | 只进行预处理和编译                                           |
| -c(小写)            | 只进行预处理、编译和汇编                                     |
| gcc(不加选项，默认) | 进行预处理、编译、汇编、链接器，默认输出可执行文件a.out      |
| -o file             | 指定生成的输出文件名为file                                   |
| -v / --version      | 查看gcc版本号                                                |
| -g                  | 生成可执行文件，进行了预处理、编译、汇编、链接器并包含调试信息 |
| -On n=0~3           | 编译优化，n越大优化得越多                                    |
| -Wall               | 提示更多警告信息                                             |
| -D                  | 编译时定义宏                                                 |

**在gcc编译时，有警告信息，默认编译器可通过且不显示警告信息**

编译时显示所有的警告信息

> gcc -Wall test.c

编译时将警告信息当做错误处理，有警告信息编译不通过

> gcc -Wall -Werror test.c

测试程序(-D选项)：

```c
#include <stdio.h>
int main(void){
#ifdef DEBUG//如果定义了宏DEBUG，就执行下面的代码，没定义就不执行
    printf("debug\n");
#endif
    printf("hello word!\n", );
	return 0;
}
```

**(-D选项) 可用于调试，调试的时候就定义DEBUG，让调试信息输出，不调试时，不定义就不会输出**

>  gcc test.c -DDebug
>
>  ./a.out
>
> debug
>
> hello word!

 **g++与gcc用法相同**

## 2.4 静态库、动态库

### 静态链接、动态链接

**静态链接**

静态链接：由链接器在链接时将库的内容加入到可执行程序中。

优点：

- 对运行环境的依赖性较小，具有较好的兼容性

缺点：

- 生成的程序比较大，需要更多的系统资源，在装入内存时会消耗更多的时间
- 库函数有了更新，必须重新编译应用程序

**动态链接**

动态链接：连接器在链接时仅仅建立与所需库函数的之间的链接关系，在程序运行时才将所需资源调入可执行程序。

优点：

- 在需要的时候才会调入对应的资源函数
- 简化程序的升级；有着较小的程序体积
- 实现进程之间的资源共享（避免重复拷贝）

缺点：

- 依赖动态库，不能独立运行
- 动态库依赖版本问题严重

系统默认采用动态链接的方式进行编译程序，若想采用静态编译，加入-static参数。

> gcc test.c -o test_share
>
> gcc -static test.c -o test_static

```c
//test.c
#include <stdio.h>
int main(){...}
```

上述test.c文件中包含stdio.h库，

静态连接：在链接阶段，将源文件中用到的库函数与汇编生成的目标文件.o合并生成可执行文件。可执行文件与库函数再无关系，放在任何环境当中都可以执行（将库stdio.h写入了可执行文件）

静态连接：在链接阶段，仅仅建立与所需库函数的之间的链接关系，在程序运行时才将所需资源调入可执行程序（程序运行时再调用库stdio.h）

------

**“程序库”**，简单说，就是包含了数据和执行码的文件。其不能单独执行，可以作为其它执行程序的一部分来完成某些功能。库的存在可以使得程序模块化，可以加快程序的再编译，可以实现代码重用,可以使得程序便于升级。**将不想给客户看的代码写在库里面，然后将库封装**

程序库可分**静态库(static library)**和**共享库(shared library)**。

### 静态库

静态库可以认为是一些目标代码的集合，是在可执行程序运行前就已经加入到执行码中，成为执行程序的一部分。

按照习惯,一般以“.a”做为文件后缀名。静态库的命名一般分为三个部分：

- 前缀：lib
- 库名称：自己命名即可
- 后缀：.a

所以最终的静态库的名字应该为：**libxxx.a**

步骤1：将c源文件生成对应的.o文件

> gcc -c add.c -o add.o
>
> gcc -c sub.c -o sub.o
>
> gcc -c mul.c -o mul.o
>
> gcc -c div.c -o div.o

步骤2：**使用打包工具ar将准备好的.o文件打包为.a文件 libtest.a**

> ar -rcs libtest.a add.o sub.o mul.o div.o

**在使用ar工具是时候需要添加参数：rcs**

- r更新
- c创建
- s建立索引

**静态库使用**

静态库制作完成之后，需要将.a文件、.h文件和测试的源文件一起发布给用户。

假设测试文件为test.c，静态库文件为libtest.a，头文件为add.h、sub.h、mul.h、div.h

编译命令：

参数说明：

- -L：表示要连接的库所在目录
- -I./: I(大写i) 表示指定头文件的目录
- -l(小写L)：指定链接时需要的库，去掉前缀和后缀

> gcc test.c -L./ -I./ -ltest -o static_out

**静态库编译出的可执行文件static_out可单独执行，不在依赖任何文件**，**修改静态库，程序输出不变(对比动态库)，库函数有了更新，必须重新编译应用程序(整个流程)**

### 动态库

共享库在程序编译时并不会被连接到目标代码中，而是在程序运行是才被载入。不同的应用程序如果调用相同的库，那么在内存里只需要有一份该共享库的实例，规避了空间浪费问题。

动态库在程序运行是才被载入，也解决了静态库对程序的更新、部署和发布页会带来麻烦。用户只需要更新动态库即可，增量更新。

按照习惯,一般以“.so”做为文件后缀名。共享库的命名一般分为三个部分：

- 前缀：lib
- 库名称：自己定义即可
- 后缀：.so

所以最终的动态库的名字应该为：libxxx.so

**动态库制作**

步骤一：生成目标文件，此时要加编译选项：-fPIC（fpic）

> gcc -fPIC -c add.c -o add.o
>
> gcc -fPIC -c sub.c
>
> gcc -fPIC -c mul.c
>
> gcc -fPIC -c div.c
>
> //选项 -o，可加可不加，会自动按原名称命名输出的.o文件

参数：-fPIC 创建与地址无关的编译程序（pic，position independent code），是为了能够在多个应用程序间共享。

步骤二：生成共享库，此时要加链接器选项: -shared（指定生成动态链接库）

> gcc -shared add.o sub.o mul.o div.o -o libtest.so

步骤三: 通过nm命令查看对应的函数是否被编译到动态库

> nm libtest.so | grep add
>
> nm libtest.so | grep sub

ldd查看可执行文件的依赖的动态库

![lld查询查询依赖的动态库](img\lld查询查询依赖的动态库.png)

**动态库测试**

引用动态库编译成可执行文件（跟静态库方式一样）

> gcc test.c -L./ -I./ -ltest -o shared_out(-I. 大写i -ltest 小写L)

然后运行：./shared_out，发现竟然报错了！！！

![动态库未定义路径报错](img\动态库未定义路径报错.png)

**当系统加载可执行代码时候，能够知道其所依赖的库的名字，但是还需要知道其路径，上面报错原因是不知道动态库的路径**

解决动态库的路径问题有下面的几个方法：

**1）**拷贝自己制作的共享库到/lib或者/usr/lib(不能是/lib64目录)

**2）**临时设置LD_LIBRARY_PATH：——**(调试时推荐这个，简单且零时，只在该终端有效)**

> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径

**3）**永久设置,把export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:库路径，设置到~/.bashrc或者 /etc/profile文件中

> deng@itcast:~/share/3rd/2share_test$ vim ~/.bashrc
>
> 最后一行添加如下内容:
>
> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/deng/share/3rd/2share_test

使环境变量生效

> deng@itcast:~/share/3rd/2share_test$ source ~/.bashrc deng@itcast:~/share/3rd/2share_test$ ./test
> a + b = 20 a - b = 10

**4）**将其添加到 /etc/ld.so.conf文件中

编辑/etc/ld.so.conf文件，加入库文件所在目录的路径

运行sudo ldconfig -v，该命令会重建/etc/ld.so.cache文件

> sudo vim /etc/ld.so.conf
>
> 文件最后添加动态库路径(绝对路径)

使生效

> sudo ldconfig -v

**5）**使用符号链接， 但是一定要使用绝对路径

> sudo ln -s /home/deng/test/6share_test/libtest.so /lib/libtest.so

## 2.5 GDB调试器

要调试C/C++的程序，首先在编译时，必须要把调试信息加到可执行文件中。使用编译器（gcc/g++）的 -g 参数可以做到这一点。如：

> g++ -g hello.cpp -o hello

如果没有-g，你将看不见程序的函数名、变量名，所代替的全是运行时的内存地址

###  启动GDB

- 启动gdb：gdb program

  program 也就是你的执行文件，一般在当前目录下

- 设置运行参数

  set args 可指定运行时参数。（如：set args 10 20 30 40 50 ）

  show args 命令可以查看设置好的运行参数。

- 启动程序

  run： 程序开始执行，如果有断点，停在第一个断点处

  start： 程序向下执行一行。

- 退出GDB：quit

### 显示源代码

用list命令来打印程序的源代码。默认打印10行。

> list linenum	打印第linenm行的上下文内容

> list function	显示函数名为function的函数的源程序

> list		显示当前行后面的源程序

> list -	  显示当前行前面的源程序

一般是打印当前行的上5行和下5行，如果显示函数是是上2行下8行，默认是10行，当然，你也可以定制显示的范围，使用下面命令可以设置一次显示源程序的行数。

> set listsize count	设置一次显示源代码的行数。

> show listsize	查看当前listsize的设置。

### 断点操作

**1）简单断点**

break 设置断点，可以简写为**b**

> b 10 设置断点，在源程序第10行

> b func 设置断点，在func函数入口处

**2）多文件设置断点**

C++中可以使用class::function或function(type,type)格式来指定函数名。

如果有名称空间，可以使用namespace::class::function或者function(type,type)格式来指定函数名。

> break filename:linenum -- 在源文件filename的linenum行处停住

> break filename:function -- 在源文件filename的function函数的入口处停住

> break class::function或function(type,type) -- 在类class的function函数的入口处停住

> break namespace::class::function -- 在名称空间为namespace的类class的function函数的入口处停住

**3）查询所有断点**

- i b	(info break的简写)

### 条件断点

一般来说，为断点设置一个条件，我们使用if关键词，后面跟其断点条件。

设置一个条件断点：

> b test.c:8 if Value == 5  //test.c的第8行Value的值为5时设置断点

### 维护断点

**delete [range...] 删除指定的断点**，其简写命令为d

- 如果不指定断点号，则表示删除所有的断点。range表示断点号的范围（如：3-7）
- 比删除更好的一种方法是disable停止点，disable了的停止点，GDB不会删除，当你还需要时，enable即可，就好像回收站一样

**disable [range...] 使指定断点无效**，简写命令是dis

如果什么都不指定，表示disable所有的停止点

**enable [range...] 使无效断点生效**，简写命令是ena

如果什么都不指定，表示enable所有的停止点

### 调试代码

> run 运行程序，可简写为r

> next 单步跟踪，函数调用当作一条简单语句执行，可简写为n

> step 单步跟踪，函数调进入被调用函数体内，可简写为s

> finish 退出进入的函数

> until 在一个循环体内单步跟踪时，这个命令可以运行程序直到退出循环体,可简写为u

> continue 继续运行程序，停在下一个断点的位置，可简写为c

> quit 退出gdb，可简写为q

### 运行时数据查看

**print** 打印变量、字符串、表达式等的值，可简写为p

> p count 打印count的值

### 自动显示

**display**设置一些自动显示的变量，当程序停住时，或是在你单步跟踪时，这些变量会自动显示。

> display 变量名

> info display -- 查看display设置的自动显示的信息。

> undisplay num（info display时显示的编号）

> delete display dnums… -- 删除自动显示，dnums意为所设置好了的自动显式的编号。如果要同时删除几个，编号可以用空格分隔(如2 5)，如果要删除一个范围内的编号，可以用减号表示（如：2-5）

> disable display dnums…

> enable display dnums…

disable和enalbe不删除自动显示的设置，而只是让其失效和恢复。

### 查看变量类型、修改变量的值

1）**ptype**  查看变量类型

> ptype aaa  //查看变量aaa的类型
>
> type = int

2）你可以使用**set var**命令来告诉GDB，aaa不是你GDB的参数，而是程序的变量名，如：

> set var aaa=10 // 将变量aaa值设置为10

**在你改变程序变量取值时，最好都使用set var格式的GDB命令**

## 2.6 Makeflie

一个工程中的源文件不计其数，用gcc指令编译太麻烦，makefile来指定编译规则。因为 makefile就像一个Shell脚本一样，其中也可以执行操作系统的命令。Makefile带来的好处就是——“自动化编译”。

**make主要解决两个问题：**

**1) 大量代码的关系维护**

大项目中源代码比较多，手工维护、编译时间长而且编译命令复杂，难以记忆及维护

把代码维护命令及编译命令写在makefile文件中，然后再用make工具解析此文件自动执行相应命令，可实现代码的合理编译

**2) 减少重复编译时间**

在改动其中一个文件的时候，能判断哪些文件被修改过，可以只对该文件进行重新编译，然后重新链接所有的目标文件，节省编译时间

**Makefile文件命名规则**

makefile和Makefile都可以，推荐使用Makefile。

**make工具的安装**

> sudo apt install make

### Makefile语法规则

**一条规则：**

> 目标：依赖文件列表
>
> ​	命令列表

Makefile基本规则三要素：

1）目标：

- 通常是要产生的文件名称，目标可以是可执行文件或其它obj文件，也可是一个动作的名称

2）依赖文件：

- 用来输入从而产生目标的文件
- 一个目标通常有几个依赖文件（可以没有）

3）命令：

- make执行的动作，一个规则可以含几个命令（可以没有）
- 有多个命令时，每个命令占一行

```makefile
test:test1 test2
    echo "test"
test1:
    echo "test1"
test2:
    echo "test2"
#test依赖test1, test2，test1和test2无依赖
#先生成依赖文件，再生成目标文件
```

### make命令格式

make是一个命令工具，它解释Makefile 中的指令（应该说是规则）。

make命令格式：

make [ -f file] [ targets ]

1.[ -f file ]：

- 可选项，make默认在工作目录中寻找名为GNUmakefile、makefile、Makefile的文件作为makefile输入文件
- -f 可以指定以上名字以外的文件作为makefile输入文件

2.[ options ]

- -v： 显示make工具的版本信息
- -w： 在处理makefile之前和之后显示工作路径
- -C dir：读取makefile之前改变工作路径至dir目录
- -n：只打印要执行的命令但不执行
- -s：执行但不显示执行的命令

3.[ targets ]：

- 若使用make命令时没有指定目标，则make工具默认会实现makefile文件内的第一个目标，然后退出
- 指定了make工具要实现的目标，目标可以是一个或多个（多个目标间用空格隔开）。

> “-”	此条命令出错，make也会继续执行后续的命令。如:“-rm main.o”
>
> “@”	不显示命令本身,只显示结果。如:“@echo clean done”

### Makefile工作原理

1）若想生成目标, 检查规则中的依赖条件是否存在,如不存在,则寻找是否有规则用来 生成该依赖文件

<img src="img\makefile工作原理_1.jpg" alt="makefile工作原理_1" style="zoom: 75%;" />



 2） 检查规则中的目标是否需要更新，必须先检查它的所有依赖,依赖中有任一个被更新,则目标必须更新

<img src="img\makefile工作原理_2.jpg" alt="makefile工作原理_2" style="zoom:75%;" />

### Makefile示例

测试程序： test.c add.c sub.c mul.c div.c

**版本1：**

缺点：效率低，修改一个文件，所有文件会被全部编译

```makefile
test:test.c add.c sub.c mul.c div.c
    gcc test.c add.c sub.c mul.c div.c -o test
```

**版本2：**——分目标编译，减少重复编译

```makefile
all:test.o add.o sub.o mul.o div.o
    gcc test.o add.o sub.o mul.o div.o
    
test.o:test.c
    gcc -c test.c
add.o:add.c
    gcc -c add.c
sub.o:sub.c
    gcc -c sub.c
mul.o:mul.c
    gcc -c mul.c
div.o:div.c
    gcc -c div.c
```

### Makefile中的变量

在Makefile中变量有点类似于C语言中的宏定义，使用该变量相当于内容替换，使Makefile易于维护,修改内容变得简单变量定义及使用。

**自定义变量**

1）定义变量方法：

变量名=变量值

2）引用变量：

$(变量名)或${变量名}

3）makefile的变量名：

- makefile变量名可以以数字开头
- 变量是大小写敏感的
- 变量一般都在makefile的头部定义
- 变量几乎可在makefile的任何地方使用

**版本3**——加入变量

```makefile
OBJS=add.o sub.o mul.o div.o test.o
all:$(OBJS)
    gcc $(OBJS)
add.o:add.c
    gcc -c add.c -o add.o
sub.o:sub.c
    gcc -c sub.c -o sub.o
mul.o:mul.c
    gcc -c mul.c -o mul.o
div.o:div.c
    gcc -c div.c -o div.o
test.o:test.c
    gcc -c test.c -o test.o
clean:
    rm -rf $(OBJS) a.out
```

除了使用用户自定义变量，makefile中也提供了一些变量（变量名大写）供用户直接使用，我们可以直接对其进行赋值。

> CC = gcc #arm-linux-gcc
>
> CPPFLAGS : C预处理的选项 如:-I
>
> CFLAGS: C编译器的选项 -Wall -g -c
>
> LDFLAGS : 链接器选项 -L -l

**makefile可执行XShell命令，版本3 中clean就是一条XShell命令，在终端输入make clean即可执行该命令**

**自动变量**

- $@: 表示目标
- $<: 表示第一个依赖
- $^: 表示所有的依赖

**注意：自动变量只能在规则的命令中中使用**

**版本4**——加入自动变量

```makefile
#变量
OBJS=add.o sub.o mul.o div.o test.o add.o
TARGET=test
CC=gcc
$(TARGET):$(OBJS)
    $(CC) $^ -o $@
add.o:add.c
	$(CC) -c $< -o $@ 
sub.o:sub.c
	$(CC) -c $< -o $@ 
mul.o:mul.c
	$(CC) -c $< -o $@ 
div.o:div.c
	$(CC) -c $< -o $@ 
test.o:test.c
	$(CC) -c $< -o $@
clean:
	rm -rf $(OBJS) $(TARGET)
```

**模式规则**

> %

**版本5**——加入模式匹配

```makefile
OBJS=test.o add.o sub.o mul.o div.o
TARGET=test
$(TARGET):$(OBJS)
    gcc $(OBJS) -o $(TARGET) 
#所有的.o依赖于.c
#有的.c生成对应的.o
%.o:%.c
    gcc -c $< -o $@
clean:
	rm -rf $(OBJS) $(TARGET)
```

### Makefile中的函数

makefile中的函数有很多，在这里给大家介绍两个最常用的。

> wildcard()	查找指定目录下的指定类型的文件
>
> src = $(wildcard *.c) //找到当前目录下所有后缀为.c的文件,赋值给变量src

> patsubst()	匹配替换
>
> obj = $(patsubst %.c,%.o, $(src)) //把src变量里所有后缀为.c的文件替换成.o

在makefile中所有的函数都是有返回值的。

**版本6**——加入函数

```makefile
SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))
TARGET=test
$(TARGET):$(OBJS)
    gcc $(OBJS) -o $(TARGET) 
%.o:%.c
    gcc -c $< -o $@
clean:
	rm -rf $(OBJS) $(TARGET)
```

### 伪目标

clean用途: 清除编译生成的中间.o文件和最终目标文件

如果当前目录下有同名clean文件，会去判断目录下的clean文件是否为最新文件，若为则不执行clean对应的命令，解决方案：伪目标

伪目标声明

> .PHONY:clean

- “-”此条命令出错，make也会继续执行后续的命令。如:“-rm main.o”
- “@”不显示命令本身,只显示结果。如:“@echo clean done”

**版本7**——加入伪目标

```makefile
SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))
TARGET=test
$(TARGET):$(OBJS)
	@gcc $(OBJS) -o $(TARGET) 
%.o:%.c
    @gcc -c $< -o $@
.PHONY:clean
clean:
    @rm -rf $(OBJS) $(TARGET)
```

总结： 一条规则，两个函数，三个变量

# 3. IO操作、文件操作、目录操作

## 3.1 系统调用和库函数调用

系统调用可被看成是一个内核与用户空间程序交互的接口——把用户进程的请求传达给内核，待内核把请求处理完毕后再将处理结果送回给用户空间。**只能通过系统调用访问内核，用户程序不能直接访问内核**

![系统调用](img\系统调用.png)

系统调用是属于操作系统内核的一部分的，必须以某种方式提供给进程让它们去调用。CPU 可以在不同的特权级别下运行，而相应的操作系统也有不同的运行级别，**用户态和内核态**。运行在内核态的进程可以毫无限制的访问各种资源，而在用户态下的用户进程的各种操作都有着限制，比如不能随意的访问内存、不能开闭中断以及切换运行的特权级别。**操作系统一般是通过软件中断从用户态切换到内核态。**

Linux 下对文件操作有两种方式：**系统调用（system call）**和**库函数调用（Library functions）**。

库函数由两类函数组成：

1）不需要调用系统调用

不需要切换到内核空间即可完成函数全部功能，并且将结果反馈给应用程序，如strcpy、bzero 等字符串操作函数。

2）需要调用系统调用

需要切换到内核空间，这类函数通过封装系统调用去实现相应功能，如 printf、fread等。

## 3.2 文件处理

### C库中IO函数工作流程

![IO工作流程](img\IO工作流程.png)

库函数访问文件的时候根据需要，设置不同类型的缓冲区，从而减少了直接调用 IO 系统调用的次数，提高了访问效率。

这个过程类似于快递员给某个区域（内核空间）送快递一样，快递员有两种方式送：

1）来一件快递就马上送到目的地，来一件送一件，这样导致来回走比较频繁（系统调用）

2）等快递攒着差不多后（缓冲区），才一次性送到目的地（库函数调用）

### 错误处理函数

errno 是记录系统的最后一次错误代码。代码是一个int型的值，在errno.h中定义。查看错误代码errno是调试程序的一个重要方法。

当Linux C api函数发**生异常时，一般会将全局变量errno赋一个整数值**，不同的值表示不同的含义，可以通过查看该值推测出错的原因。

```c++
#include <errno.h>  //errno
#include <string.h> //strerror(errno)
	printf("%d\n", errno);  			//打印错误码
	printf("%s\n", strerror(errno));	//把errno的数字转换成相应的文字
	perror("fopen err");    			//打印错误原因的字符串
```

查看错误号：

> /usr/include/asm-generic/errno-base.h
>
> /usr/include/asm-generic/errno.h

### 虚拟地址空间

**每个进程都会分配虚拟地址空间**，在32位机器上，该地址空间为4G 。

![虚拟地址空间](img\虚拟地址空间.png)

在进程里平时所说的指针变量，保存的就是虚拟地址。当应用程序使用虚拟地址访问内存时，处理器（CPU）会将其转化成物理地址（MMU）。

MMU：将虚拟的地址转化为物理地址。

这样做的好处在于：

- 进程隔离，更好的保护系统安全运行
- 屏蔽物理差异带来的麻烦，方便操作系统和编译器安排进程地址

### 文件描述符

在 Linux中，一切设备皆文件。我们可以系统调用中 I/O 的函数，对文件进行相应的操作（ open()、close()、write() 、read() 等）。

打开现存文件或新建文件时，系统（内核）会返回一个文件描述符，文件描述符用来指定已打开的文件。这个文件描述符相当于这个已打开文件的标号，文件描述符是非负整数，是文件的标识，操作这个文件描述符相当于操作这个描述符所指定的文件。

程序运行起来后（每个进程）都有一张文件描述符的表，标准输入、标准输出、标准错误输出设备文件被打开，对应的文件描述符 0、1、2 记录在表中。程序运行起来后这三个文件描述符是默认打开的。因此，**新打开的文件描述符从3开始**

```c++
#define STDIN_FILENO  0 //标准输入的文件描述符
#define STDOUT_FILENO 1 //标准输出的文件描述符
#define STDERR_FILENO 2 //标准错误的文件描述符
```

在程序运行起来后打开其他文件时，系统会返回文件描述符表中最小可用的文件描述符，并将此文件描述符记录在表中。

<img src="img\文件描述符.png" alt="文件描述符" style="zoom:67%;" />

**最大打开的文件个数**

Linux 中一个进程最多只能打开 NR_OPEN_DEFAULT （即1024）个文件，故当文件不再使用时应及时调用 close() 函数关闭文件。

- 查看当前系统允许打开最大文件个数：

  > cat /proc/sys/fs/file-max

- 当前默认设置最大打开文件个数1024

  > ulimit -a

- 修改默认设置最大打开文件个数为4096

  > ulimit -n 4096

## 3.3 常用文件IO函数

### open函数

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
功能：
    打开文件，如果文件不存在则可以选择创建。
参数：
    pathname：文件的路径及文件名
    flags：打开文件的行为标志，必选项 O_RDONLY, O_WRONLY, O_RDWR
    mode：这个参数，只有在文件不存在时有效，指新建文件时指定文件的权限
返回值：
    成功：成功返回打开的文件描述符
    失败：-1
```

**flags详细说明**

必选项：

| **取值** | **含义**               |
| :------- | :--------------------- |
| O_RDONLY | 以只读的方式打开       |
| O_WRONLY | 以只写的方式打开       |
| O_RDWR   | 以可读、可写的方式打开 |

可选项，和必选项按位或起来

| **取值**   | **含义**                                                   |
| :--------- | :--------------------------------------------------------- |
| O_CREAT    | 文件不存在则创建文件，使用此选项时需使用mode说明文件的权限 |
| O_EXCL     | 如果同时指定了O_CREAT，且文件已经存在，则出错              |
| O_TRUNC    | 如果文件存在，则清空文件内容                               |
| O_APPEND   | 写文件时，数据添加到文件末尾                               |
| O_NONBLOCK | 对于设备文件, 以O_NONBLOCK方式打开可以做非阻塞I/O          |

**mode补充说明**

1\) 文件最终权限：mode & ~umask

2\) shell进程的umask掩码可以用umask命令查看

> umask：查看掩码（补码）
>
> umask mode：设置掩码，mode为八进制数
>
> umask -S：查看各组用户的默认操作权限

| **取值** | **八进制** | 含义                                   |
| :------- | :--------- | :------------------------------------- |
| S_IRWXU  | 00700      | 文件所有者的读、写、可执行权限         |
| S_IRUSR  | 00400      | 文件所有者的读权限                     |
| S_IWUSR  | 00200      | 文件所有者的写权限                     |
| S_IXUSR  | 00100      | 文件所有者的可执行权限                 |
| S_IRWXG  | 00070      | 文件所有者同组用户的读、写、可执行权限 |
| S_IRGRP  | 00040      | 文件所有者同组用户的读权限             |
| S_IWGRP  | 00020      | 文件所有者同组用户的写权限             |
| S_IXGRP  | 00010      | 文件所有者同组用户的可执行权限         |
| S_IRWXO  | 00007      | 其他组用户的读、写、可执行权限         |
| S_IROTH  | 00004      | 其他组用户的读权限                     |
| S_IWOTH  | 00002      | 其他组用户的写权限                     |
| S_IXOTH  | 00001      | 其他组用户的可执行权限                 |

### close函数

```c
#include <unistd.h>
int close(int fd);
功能：
    关闭已打开的文件
参数：
    fd : 文件描述符，open()的返回值
返回值：
    成功：0
    失败： -1, 并设置errno
```

需要说明的是，当一个进程终止时，内核对该进程所有尚未关闭的文件描述符调用close关闭，所以即使用户程序不调用close，在终止时内核也会自动关闭它打开的所有文件。

但是对于一个长年累月运行的程序(比如网络服务器)，打开的文件描述符一定要记得关闭,否则随着打开的文件越来越多，会占用大量文件描述符和系统资源。

###  write函数

```c
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count);
功能：
    把指定数目的数据写到文件（fd）
参数：
    fd :  文件描述符
    buf : 数据首地址
    count : 写入数据的长度（字节）
返回值：
    成功：实际写入数据的字节个数
    失败： - 1
```

### read函数

```c
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
功能：
    把指定数目的数据读到内存（缓冲区）
参数：
    fd : 文件描述符
    buf : 内存首地址
    count : 读取的字节个数
返回值：
    成功：实际读取到的字节个数
    失败： - 1
```

**阻塞和非阻塞的概念**

读写常规文件是不会阻塞的(缓冲区不会满)，不管读多少字节，读写完，一定会在有限的时间内返回

从终端设备或网络读写则不一定，读写缓冲区满时，调用read或write就会阻塞，一直阻塞至可写或可读

【注意】阻塞与非阻塞是对于文件而言的，而不是指read、write等的属性。

以非阻塞方式打开文件程序示例：

```c
#include <unistd.h> //read
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h> //EAGAIN
//如果为非阻塞，但是没有数据可读，此时全局变量 errno 被设置为 EAGAIN
int main()
{
    // /dev/tty --> 当前终端设备
    // 以不阻塞方式(O_NONBLOCK)打开终端设备
    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    char buf[10];
    int n;
    n = read(fd, buf, sizeof(buf));
    if (n < 0){
        // 如果为非阻塞，但是没有数据可读，此时全局变量 errno 被设置为 EAGAIN
        if (errno != EAGAIN){
            perror("read /dev/tty");
            return -1;
        }
        printf("没有数据\n");
    }
    return 0;
}
```

### lseek函数

```c
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
功能：
    改变文件的偏移量
参数：
    fd：文件描述符
    offset：根据whence来移动的位移数（偏移量），可以是正数，也可以负数，如果正数，则相对于whence往右移动，如果是负数，则相对于whence往左移动。如果向前移动的字节数超过了文件开头则出错返回，如果向后移动的字节数超过了文件末尾，再次写入时将增大文件尺寸。
    whence：其取值如下：
        SEEK_SET：从文件开头移动offset个字节
        SEEK_CUR：从当前位置移动offset个字节
        SEEK_END：从文件末尾移动offset个字节
返回值：
    若lseek成功执行, 则返回新的偏移量
    如果失败， 返回-1
```

所有打开的文件都有一个当前文件偏移量(current file offset)，以下简称为 cfo。cfo 通常是一个非负整数，用于表明文件开始处到文件当前位置的字节数。

读写操作通常开始于 cfo，并且使 cfo 增大，增量为读写的字节数。文件被打开时，cfo 会被初始化为 0，除非使用了 O_APPEND 。

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
//lseek使用
int main()}{
    int fd=-1;
    //1.打开文件
    fd = open("txt",O_RDWR|O_CREAT,0644);
    printf("fd=%d\n",fd);
    //2.lessk操作
    write(fd,"ABCDEFG",7);
    
    lseek(fd,32,SEEK_SET);//从文件开头偏移32个字节
    write(fd,"1234567890",10);//再写
    
    char buf[128]={0};
    //此时fd文件偏移量在文件末尾，一读就直接结束了,必须将fd的偏移量回到文件起点才能读到数据
    lseek(fd,0,SEEK_SET);
    int n=read(fd,buf,sizeof(buf));
    printf("n:%d,buf:%s",n,buf);
    //3.关闭文件
    close(fd);
}
```

## 3.4 文件操作相关函数

### stat函数——获取文件状态信息

**stat命令，可直接用stat查询文件属性**，或调用函数

> stat filename	//查询file属性

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *path, struct stat *buf);
int lstat(const char *pathname, struct stat *buf);
功能：
    获取文件状态信息
    stat和lstat的区别：
        当文件是一个符号链接时，lstat返回的是该符号链接本身的信息；
        而stat返回的是该链接指向的文件的信息。
参数：
    path：文件名
    buf：保存文件信息的结构体
返回值：
    成功： 0
    失败: -1
```

struct stat结构体说明：

```c
struct stat {
    dev_t           st_dev;     	//文件的设备编号
    ino_t           st_ino;     	//节点
    mode_t          st_mode;		//文件的类型和存取的权限
    nlink_t         st_nlink;       //连到该文件的硬连接数目，刚建立的文件值为1
    uid_t           st_uid;     	//用户ID
    gid_t           st_gid;     	//组ID
    dev_t           st_rdev;        //(设备类型)若此文件为设备文件，则为其设备编号
    off_t           st_size;        //文件字节数(文件大小)
    blksize_t       st_blksize;     //块大小(文件系统的I/O 缓冲区大小)
    blkcnt_t        st_blocks;      //块数
    time_t          st_atime;       //最后一次访问时间
    time_t          st_mtime;       //最后一次修改时间
    time_t          st_ctime;       //最后一次改变时间(指属性)
};
```

其中文件的类型和存取的权限st_mode为mode_t类型的结构体(16位整数)，参数说明如下：

```markdown
The following mask values are defined for the file type of the st_mode field:
	S_IFMT     0170000   bit mask for the file type bit field

	S_IFSOCK   0140000   socket
	S_IFLNK    0120000   symbolic link
	S_IFREG    0100000   regular file
	S_IFBLK    0060000   block device
	S_IFDIR    0040000   directory
	S_IFCHR    0020000   character device
	S_IFIFO    0010000   FIFO
//st_mode包含文件类型和存取的权限
```

### fcnlt函数——改变已打开的文件性质

```c
#include <unistd.h>
#include <fcntl.h>
int fcntl(int fd, int cmd, ... /* arg */);
功能：改变已打开的文件性质，fcntl针对描述符提供控制。
参数：
    fd：操作的文件描述符
    cmd：操作方式
    arg：针对cmd的值，fcntl能够接受第三个参数int arg。
返回值：
    成功：返回某个其他值
    失败：-1
```

fcntl函数有5种功能：

> 1\) 复制一个现有的描述符（cmd=F_DUPFD）
>
> 2\) 获得/设置文件描述符标记(cmd=F_GETFD或F_SETFD)
>
> 3\) 获得/设置文件状态标记(cmd=F_GETFL或F_SETFL)	//只能修改部分的文件状态标记，有些不能修改
>
> 4\) 获得/设置异步I/O所有权(cmd=F_GETOWN或F_SETOWN)
>
> 5\) 获得/设置记录锁(cmd=F_GETLK, F_SETLK或F_SETLKW)

### access函数——测试指定文件是否具有某种属性

```c
#include <unistd.h>
int access(const char *pathname, int mode);
功能：测试指定文件是否具有某种属性
参数：
    pathname：文件名
    mode：文件权限，4种权限
        R_OK：   是否有读权限
        W_OK：   是否有写权限
        X_OK：   是否有执行权限
        F_OK：   测试文件是否存在
返回值：
    0：  有某种权限，或者文件存在
    -1：没有，或文件不存在
```

### chmod函数——修改文件权限

```c
#include <sys/stat.h>
int chmod(const char *pathname, mode_t mode);
功能：修改文件权限
参数：
    filename：文件名
    mode：权限(8进制数)
返回值：
    成功：0
    失败：-1
```

### chown函数——修改文件所有者和所属组

```c
#include <unistd.h>
int chown(const char *pathname, uid_t owner, gid_t group);
功能：修改文件所有者和所属组
参数：
    pathname：文件或目录名
    owner：文件所有者id，通过查看 /etc/passwd 得到所有者id
    group：文件所属组id，通过查看 /etc/group 得到用户组id
返回值：
    成功：0
    失败：-1
```

### truncate函数——修改文件大小

```c
#include <unistd.h>
#include <sys/types.h>
int truncate(const char *path, off_t length);
功能：修改文件大小
参数：
    path：文件文件名字
    length：指定的文件大小
        a)比原来小, 删掉后边的部分
        b)比原来大, 向后拓展
返回值：
    成功：0
    失败：-1
```

### link函数——创建一个硬链接

```c
#include <unistd.h>
int link(const char *oldpath, const char *newpath);
功能：创建一个硬链接
参数：
    oldpath：源文件名字
    newpath：硬链接名字
返回值：
    成功：0
    失败：-1
```

### symlink函数——创建一个软链接

```c
#include <unistd.h>
int symlink(const char *target, const char *linkpath);
功能：创建一个软链接
参数：
    target：源文件名字
    linkpath：软链接名字
返回值：
    成功：0
    失败：-1
```

### readlink函数——读软连接对应的文件名

```c
#include <unistd.h>
ssize_t readlink(const char *pathname, char *buf, size_t bufsiz);
功能：读软连接对应的文件名，不是读内容(该函数只能读软链接文件)
参数：
    pathname：软连接名
    buf：存放软件对应的文件名
    bufsiz ：缓冲区大小(第二个参数存放的最大字节数)
返回值：
    成功：>0，读到buf中的字符个数
    失败：-1
```

### unlink函数——删除一个文件(软硬链接文件)

```c
#include <unistd.h>
int unlink(const char *pathname);
功能：删除一个文件(软硬链接文件)
参数：
    pathname：删除的文件名字
返回值：
    成功：0
    失败：-1
```

### rename函数——把oldpath的文件名改为newpath

```c
#include <stdio.h>
int rename(const char *oldpath, const char *newpath);
功能：把oldpath的文件名改为newpath
参数：
oldpath：旧文件名
newpath：新文件名
返回值：
成功：0
失败：-1
```

##  3.5 文件描述符复制(重点)

dup() 和 dup2() 是两个非常有用的系统调用，都是用来复制一个文件的描述符，使新的文件描述符也标识旧的文件描述符所标识的文件。通过原来的文件描述符复制出一个新的文件描述符，这样的话，原来的文件描述符和新的文件描述符都指向同一个文件，我们操作这两个文件描述符的任何一个，都能操作它所对应的文件。

每个文件在打开时都会对应一个文件表，记录文件状态，当前文件偏移量，文件存储位置。**dup() 和 dup2() 都是让新的文件描述符指向老的文件描述符对应的文件表**

![dup执行后](C:\Users\ouyang\Desktop\0.linux系统编程知识\img\dup执行后.png)

### dup函数

```c
#include <unistd.h>
int dup(int oldfd);
功能：
    通过 oldfd 复制出一个新的文件描述符，新的文件描述符是调用进程文件描述符表中最小可用的文件描述符，最终 oldfd 和新的文件描述符都指向同一个文件。
参数：
    oldfd : 需要复制的文件描述符 oldfd
返回值：
        成功：新文件描述符
        失败： -1
```

### dup2函数

```c
#include <unistd.h>
int dup2(int oldfd, int newfd);
功能：
    通过 oldfd 复制出一个新的文件描述符 newfd，如果成功，newfd 和函数返回值是同一个返回值，最终 oldfd 和新的文件描述符 newfd 都指向同一个文件。
参数：
    oldfd : 需要复制的文件描述符
    newfd : 新的文件描述符，这个描述符可以人为指定一个合法数字（0 - 1023），如果指定的数字已经被占用（和某个文件有关联），此函数会自动关闭 close() 断开这个数字和某个文件的关联，再来使用这个合法数字。
返回值：
    成功：返回 newfd
    失败：返回 -1
```

**示例：**

<img src="img\文件描述符复制.png" alt="文件描述符复制" style="zoom:120%;" />

## 3.6 目录相关操作(掌握)

### getcwd函数——获取当前进程的工作目录

```c
#include <unistd.h>
char *getcwd(char *buf, size_t size);
功能：获取当前进程的工作目录
参数：
    buf : 缓冲区，存储当前的工作目录
    size : 缓冲区大小
返回值：
    成功：buf中保存当前进程工作目录位置
    失败：NULL
```

### chdir函数——修改当前进程(应用程序)的路径

```c
#include <unistd.h>
int chdir(const char *path);
功能：修改当前进程(应用程序)的路径
参数：
    path：切换的路径
返回值：
    成功：0
    失败：-1
```

### opendir函数——打开一个目录

```c
#include <sys/types.h>
#include <dirent.h>
DIR *opendir(const char *name);
功能：打开一个目录
参数：
    name：目录名
返回值：
    成功：返回指向该目录结构体指针
    失败：NULL
```

### closedir函数——关闭目录

```c
#include <sys/types.h>
#include <dirent.h>
int closedir(DIR *dirp);
功能：关闭目录
参数：
    dirp：opendir返回的指针
返回值：
    成功：0
    失败：-1
```

### readdir函数——读取目录

```c
#include <dirent.h>
struct dirent *readdir(DIR *dirp);
功能：读取目录
参数：
    dirp：opendir的返回值
返回值：
    成功：目录结构体指针
    失败：NULL
```

相关结构体说明：

```c
struct dirent
{
    ino_t d_ino;                  	// 此目录进入点的inode
    off_t d_off;                    // 目录文件开头至此目录进入点的位移
    signed short int d_reclen;      // d_name 的长度, 不包含NULL 字符
    unsigned char d_type;           // d_type 所指的文件类型 
    char d_name[256];               // 文件名
};
```

d_type文件类型说明：

| **取值**   | **含义** |
| :--------- | :------- |
| DT_BLK     | 块设备   |
| DT_CHR     | 字符设备 |
| DT_DIR     | 目录     |
| DT_LNK     | 软链接   |
| DT_FIFO    | 管道     |
| DT_REG     | 普通文件 |
| DT_SOCK    | 套接字   |
| DT_UNKNOWN | 未知     |

```c
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<dirent.h>
int main(){
    DIR *dir=NULL;
    struct dirent *d=NULL;
    //打开目录
    dir=opendir("4filedir");
    if(dir==NULL){
        perror("opendir");
        return -1;
    }
    printf("打开目录成功\n");
    //循环读取目录的全面内容(.	..	和目录下的文件)
    while(1){
        d=readdir(dir);
        if(d==NULL)break;
        printf("d_type:%hu d_name:%s\n",d->d_type,d->d_name);
    }
    closedir(dir);
}
```

![readdir()](img\readdir().png)



## 3.7 时间相关函数

utime、time

```
char *asctime(const struct tm *tm);
char *asctime_r(const struct tm *tm, char *buf);

char *ctime(const time_t *timep);
char *ctime_r(const time_t *timep, char *buf);

struct tm *gmtime(const time_t *timep);
struct tm *gmtime_r(const time_t *timep, struct tm *result);

struct tm *localtime(const time_t *timep);
struct tm *localtime_r(const time_t *timep, struct tm *result);

time_t mktime(struct tm *tm);
```

# 4. 进程控制

## 4.1 基本概念

**单道程序设计、多道程序设计**	同时存放几道相互独立的程序，它们在管理程序控制之下，相互穿插的运行。多道程序设计必须有硬件基础作为保证。

### 并行和并发(理解)

**并行(parallel)：**指在同一时刻，有多条指令在多个处理器上同时执行

**并发(concurrency)：**指在同一时刻只能有一条指令执行，但多个进程指令被快速的轮换执行，使得在宏观上具有多个进程同时执行的效果，但在微观上并不是同时执行的，只是把时间分成若干段，使多个进程快速交替的执行。**计算机采用的是并发**

###  MMU(了解)

MMU是Memory Management Unit的缩写，中文名是[内存管理](https://baike.baidu.com/item/内存管理)单元，它是[中央处理器](https://baike.baidu.com/item/中央处理器)（CPU）中用来管理[虚拟存储器](https://baike.baidu.com/item/虚拟存储器)、物理存储器的控制线路，同时也负责[虚拟地址](https://baike.baidu.com/item/虚拟地址)映射为[物理地址](https://baike.baidu.com/item/物理地址)，以及提供硬件机制的内存访问授权，多用户多进程操作系统。

<img src="img\MMU.png" alt="MMU" style="zoom:70%;" />

### 进程控制块PCB(了解)

进程运行时，内核为进程每个进程分配一个PCB（进程控制块），维护进程相关的信息，Linux内核的进程控制块是task_struct结构体。

在 /usr/src/linux-headers-xxx/include/linux/sched.h 文件中可以查看struct task_struct 结构体定义：

> vim /usr/src/linux-headers-4.10.0-28/include/linux/sched.h

其内部成员有很多，我们掌握以下部分即可：

- 进程id。系统中每个进程有唯一的id，在C语言中用pid_t类型表示，其实就是一个非负整数。
- 进程的状态，有就绪、运行、挂起、停止等状态。
- 进程切换时需要保存和恢复的一些CPU寄存器。
- 描述虚拟地址空间的信息。
- 描述控制终端的信息。
- 当前工作目录（Current Working Directory）。
- umask掩码。
- 文件描述符表，包含很多指向file结构体的指针。
- 和信号相关的信息。
- 用户id和组id。
- 会话（Session）和进程组。
- 进程可以使用的资源上限（Resource Limit）。

### 进程的状态(重点)

进程状态反映进程执行过程的变化。这些状态随着进程的执行和外界条件的变化而转换。

在三态模型中，进程状态分为三个基本状态，即**运行态，就绪态，阻塞态**。

在五态模型中，进程分为**新建态、终止态，运行态，就绪态，阻塞态**。

<img src="img\进程的状态.png" alt="进程的状态" style="zoom:80%;" />

**①TASK_RUNNING：**进程正在被CPU执行。当一个进程刚被创建时会处于TASK_RUNNABLE，表示己经准备就绪，正等待被调度。

**②TASK_INTERRUPTIBLE（可中断）：**进程正在睡眠（也就是说它被阻塞）等待某些条件的达成。一旦这些条件达成，内核就会把进程状态设置为运行。处于**此状态的进程也会因为接收到信号而提前被唤醒**，**比如给一个TASK_INTERRUPTIBLE状态的进程发送SIGKILL信号，这个进程将先被唤醒（进入TASK_RUNNABLE状态），然后再响应SIGKILL信号而退出**（变为TASK_ZOMBIE状态），并不会从TASK_INTERRUPTIBLE状态直接退出。

**③TASK_UNINTERRUPTIBLE（不可中断）：**处于等待中的进程，待资源满足时被唤醒，**但不可以由其它进程通过信号或中断唤醒**。由于不接受外来的任何信号，**因此无法用kill杀掉这些处于该状态的进程**。而**TASK_UNINTERRUPTIBLE状态存在的意义就在于**，**内核的某些处理流程是不能被打断的**。如果响应异步信号，程序的执行流程中就会被插入一段用于处理异步信号的流程，于是原有的流程就被中断了，这可能使某些设备陷入不可控的状态。处于TASK_UNINTERRUPTIBLE状态一般总是非常短暂的，通过ps命令基本上不可能捕捉到。

**④TASK_ZOMBIE（僵死）：**表示进程已经结束了，**但是其父进程还没有调用wait4或waitpid()来释放进程描述符**。为了父进程能够获知它的消息，子进程的进程描述符仍然被保留着。一旦父进程调用了wait4()，进程描述符就会被释放。

**⑤TASK_STOPPED（停止）：**进程停止执行。当进程接收到SIGSTOP，SIGTSTP，SIGTTIN，SIGTTOU等信号的时候。此外，**在调试期间接收到任何信号**，都会使进程进入这种状态。**当接收到SIGCONT信号，会重新回到TASK_RUNNABLE**。

如何查看进程状态：

> ps -aux

stat的参数意义如下：

| **参数** | **含义**                               |
| :------- | :------------------------------------- |
| D        | 不可中断 Uninterruptible（usually IO） |
| R        | 正在运行，或在队列中的进程             |
| S(大写)  | 处于休眠状态                           |
| T        | 停止或被追踪                           |
| Z        | 僵尸进程                               |
| W        | 进入内存交换（从内核2.6开始无效）      |
| X        | 死掉的进程                             |
| <        | 高优先级                               |
| N        | 低优先级                               |
| s        | 包含子进程                             |
| +        | 位于前台的进程组                       |

## 4.2 进程的相关命令

### ps

进程是一个具有一定独立功能的程序，它是操作系统动态执行的基本单元。

ps命令可以查看进程的详细状况，常用选项(选项可以不加“-”)如下：

| **选项** | **含义**                                 |
| :------- | :--------------------------------------- |
| -a       | 显示终端上的所有进程，包括其他用户的进程 |
| -u       | 显示进程的详细状态                       |
| -x       | 显示没有控制终端的进程                   |
| -j       | 列出与作业控制相关的信息                 |
| -w       | 显示加宽，以便显示更多的信息             |
| -r       | 只显示正在运行的进程                     |

> 显示当前用户下所有进程：**ps aux**
>
> 以比较完整的格式显示所有的进程：**ps ajx**
>
> 显示终端上的所有进程 **ps -a**

### top

top命令用来**动态显示运行中的进程**。top命令能够在运行后，在指定的时间间隔更新显示信息。可以在使用top命令时加上-d 来指定显示信息更新的时间间隔。

在top命令执行后，可以按下按键得到对显示的结果进行排序：

| **按键** | **含义**                           |
| :------- | :--------------------------------- |
| M        | 根据内存使用量来排序               |
| P        | 根据CPU占有率来排序                |
| T        | 根据进程运行时间的长短来排序       |
| U        | 可以根据后面输入的用户名来筛选进程 |
| K        | 可以根据后面输入的PID来杀死进程。  |
| q        | 退出                               |
| h        | 获得帮助                           |

### kill

kill通过进程号杀死进程，需要配合 ps 使用。

使用格式：

> kill [-signal] pid

信号值从0到15，其中9为绝对终止，可以处理一般信号无法终止的进程。

> kill 9133 	杀死进程号为9133 的进程号

查看信号编号: kill -l(字母)

![信号编号](img\信号编号.png)

有些进程不能直接杀死，这时候我们需要加一个参数“-9”，使用9号信号SIGKILL

杀死进程: kill -SIGKILL/(-9) 9133 [进程标识号]

### killall

**通过进程名杀死进程**

> killall [-signal] 进程名

> killall sleep	杀死所有的sleep进程

## 4.3 进程号和相关函数

每个进程都由一个进程号来标识，其类型为 pid_t（整型），进程号的范围：0～32767。进程号总是唯一的，但进程号可以重用。当一个进程终止后，其进程号就可以再次使用。

**进程号（PID）**：

标识进程的一个非负整型数。

**父进程号（PPID）**：

任何进程（ 除 init 进程）都是由另一个进程创建，该进程称为被创建进程的父进程，对应的进程号称为父进程号（PPID）。如，A 进程创建了 B 进程，A 的进程号就是 B 进程的父进程号。

**进程组号（PGID）**：

进程组是一个或多个进程的集合。他们之间相互关联，进程组可以接收同一终端的各种信号，关联的进程有一个进程组号（PGID）。类似QQ群

### getpid函数

```c
#include <sys/types.h>
#include <unistd.h>
pid_t getpid(void);
功能：
    获取本进程号（PID）
参数：
    无
返回值：
    本进程号
```

### getppid函数

```c
#include <sys/types.h>
#include <unistd.h>
pid_t getppid(void);
功能：
    获取调用此函数的进程的父进程号（PPID）
参数：
    无
返回值：
    调用此函数的进程的父进程号（PPID）
```

###  getpgid函数

```c
#include <sys/types.h>
#include <unistd.h>
pid_t getpgid(pid_t pid);
功能：
    获取进程组号（PGID）
参数：
    pid：进程号
返回值：
    参数为 0 时返回当前进程组号，否则返回参数指定的进程的进程组号
```

## 4.4 父子进程

### fork()	进程的创建

系统允许一个进程创建新进程，新进程即为子进程，子进程还可以创建新的子进程，形成进程树结构模型。

```c
#include <sys/types.h>
#include <unistd.h>
pid_t fork(void);
功能：
    用于从一个已存在的进程中创建一个新进程，新进程称为子进程，原进程称为父进程。
参数：
    无
返回值：
    成功：子进程中返回 0，父进程中返回子进程 ID。pid_t，为整型。
    失败：返回-1。
    失败的两个主要原因是：
        1）当前的进程数已经达到了系统规定的上限，这时 errno 的值被设置为 EAGAIN。
        2）系统内存不足，这时 errno 的值被设置为 ENOMEM。
```

### 父子进程关系

**使用 fork() 函数得到的子进程是父进程的一个复制品，它从父进程处继承了整个进程的地址空间**：包括进程上下文（进程执行活动全过程的静态描述）、进程堆栈、打开的文件描述符、信号控制设定、进程优先级、进程组号等。

子进程所独有的只有它的进程号，计时器等（只有小量信息）。因此，使用 **fork() 函数的代价是很大的**。

<img src="img\父子进程关系.png" alt="父子进程关系" style="zoom:67%;" />

实际上，更准确来说，Linux 的 fork() 使用是**读时共享，写时拷贝**。读时共享，写时拷贝是一种可以推迟甚至避免拷贝数据的技术。内核此时并不复制整个进程的地址空间，而是让父子进程共享同一个地址空间。只用在需要写入的时候才会复制地址空间，从而使各个进行拥有各自的地址空间。也就是说，资源的复制是在需要写入的时候才会进行，在此之前，只有以只读方式共享。

注意：fork之后父子进程共享文件，**fork产生的子进程与父进程相同的文件文件描述符指向相同的文件表，引用计数增加，共享文件文件偏移指针。**

### 区分父子进程

子进程是父进程的一个复制品，fork() 函数被调用一次，但返回两次。两次返回的区别是：子进程的返回值是 0，而父进程的返回值则是新子进程的进程 ID。

### 父子进程地址空间

父子进程各自的地址空间是独立的，包括全家变量、静态变量等，改变一个进程的变量值不会影响另一个进程的变量。

注意：**在父进程fork()之前申请的内存，需要在父进程和子进程中各释放一次**，一次申请，两次释放。

valgrind	判断程序执行前后的内存申请和内存释放，可用于内存泄漏的调试

> valgrind ./a.out

### GDB调试多进程

使用gdb调试的时候，gdb只能跟踪一个进程。可以在fork函数调用之前，通过指令设置gdb调试工具跟踪父进程或者是跟踪子进程。默认跟踪父进程。

> set follow-fork-mode child 设置gdb在fork之后跟踪子进程。
>
> set follow-fork-mode parent 设置跟踪父进程（默认）。

注意，一定要在fork函数调用之前设置才有效。

## 4.5 进程退出

### 进程退出函数

**exit()、_exit()**

```c
#include <stdlib.h>
void exit(int status);
#include <unistd.h>
void _exit(int status);
功能：
    结束调用此函数的进程。
参数：
    status：返回给父进程的参数（低 8 位有效），至于这个参数是多少根据需要来填写。
返回值：
    无
```

exit() 和 exit() 函数功能和用法是一样的，包含的头文件不一样，还有的区别就是：exit()属于标准库函数，exit()属于系统调用函数。

![进程退出函数](img\进程退出函数.png)

**exit()退出进程会清理I/O缓冲区(会将缓冲区的东西输入或输出)，_exit()直接结束进程进入到内核中(将缓冲区的东西丢弃)**

所以exit()将缓冲区的数据写完后才能退出来，所以调用exit()函数后程序并不会马上退出，这就是有些出现的僵尸程序，而_exit是直接退出进入到内核中去。

### 等待子进程退出函数

在每个进程退出的时候，内核释放该进程所有的资源、包括打开的文件、占用的内存等。但是仍然为其保留一定的信息，这些信息主要主要指进程控制块PCB的信息（包括进程号、退出状态、运行时间等）。

父进程可以通过调用wait或waitpid得到它的退出状态同时彻底清除掉这个进程。

wait() 和 waitpid() 函数的功能一样，区别在于，**wait() 函数会阻塞**，**waitpid() 可以设置不阻塞，waitpid() 还可以指定等待哪个子进程结束**。

注意：**一次wait或waitpid调用只能清理一个子进程，清理多个子进程应使用循环**

#### wait函数

```c
#include <sys/types.h>
#include <sys/wait.h>
pid_t wait(int *status);
功能：
    等待任意一个子进程结束，如果任意一个子进程结束了，此函数会回收该子进程的资源。
参数：
    status : 进程退出时的状态信息。
返回值：
    成功：已经结束子进程的进程号
    失败： -1
```

调用 wait() 函数的进程会挂起（阻塞），直到它的一个子进程退出或收到一个不能被忽视的信号时才被唤醒（相当于继续往下执行）。

若调用进程没有子进程，该函数立即返回；若它的子进程已经结束，该函数同样会立即返回，并且会回收那个早已结束进程的资源。

所以，wait()函数的主要功能为回收已经结束子进程的资源。

如果参数 status 的值不是 NULL，wait() 就会把子进程退出时的状态取出并存入其中，这是一个整数值（int），指出了子进程是正常退出还是被非正常结束的。

这个退出信息在一个 int 中包含了多个字段，直接使用这个值是没有意义的，我们需要用宏定义取出其中的每个字段。

**宏函数可分为如下三组：**

> WIFEXITED(status)为真 → 进程正常结束 → WEXITSTATUS(status)获取进程退出状态 (exit的参数)

> WIFSIGNALED(status)为真 → 进程异常终止 → WTERMSIG(status)获取得使进程终止的那个信号的编号

> WIFSTOPPED(status)为真 → 进程处于暂停状态 → WSTOPSIG(status)获取得使进程暂停的那个信号的编号
>
> ​											 →WIFCONTINUED(status)为真 → 进程暂停后已经继续运行

**例子：**

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
    pid_t pid =-1;
    int status=0;
    int i;
    pid =fork();
    if(pid==0){//子进程
        for(i=0;i<5;i++){
            printf("child process %d do sth %d\n",getpid(),i+1);
            sleep(5);
        }
        exit(10);
    }
    //父进程
    printf("父进程等待子进程结束，回收其资源\n");
    wait(&status);
    //正常退出
    if(WIFEXITED(status)){
        printf("子进程退出状态码%d\n",WEXITSTATUS(status));
    }
    //子进程被杀死
    else if(WIFSIGNALED(status)){
        printf("子进程被信号%d杀死\n",WTERMSIG(status));
    }
    else if(WIFSTOPPED(status)){
        printf("子进程被信号：%d中断\n",WSTOPSIG(status));
    }
    return 0;
}
```

```c
kill 进程号	//默认kill -15
kill -9 进程号
kill -19 进程号	//暂停进程
kill -18 进程号	//恢复进程
```

#### waitpid函数

```c
#include <sys/types.h>
#include <sys/wait.h>
pid_t waitpid(pid_t pid, int *status, int options);
功能：
    等待子进程终止，如果子进程终止了，此函数会回收子进程的资源。

参数：
    pid : 参数 pid 的值有以下几种类型：
      pid > 0  等待进程 ID 等于 pid 的子进程。
      pid = 0  等待同一个进程组中的任何子进程，如果子进程已经加入了别的进程组，waitpid 不会等待它。
      pid = -1 等待任一子进程，此时 waitpid 和 wait 作用一样。
      pid < -1 等待指定进程组中的任何子进程，这个进程组的 ID 等于 pid 的绝对值。

    status : 进程退出时的状态信息。和 wait() 用法一样。

    options : options 提供了一些额外的选项来控制 waitpid()。
            0：同 wait()，阻塞父进程，等待子进程退出。
            WNOHANG：没有任何已经结束的子进程，则立即返回。
            WUNTRACED：如果子进程暂停了则此函数马上返回，并且不予以理会子进程的结束状态。（由于涉及到一些跟踪调试方面的知识，加之极少用到）
                 
返回值：
    waitpid() 的返回值比 wait() 稍微复杂一些，一共有 3 种情况：
        1) 当正常返回的时候，waitpid() 返回收集到的已经回收子进程的进程号；
        2) 如果设置了选项 WNOHANG，而调用中 waitpid() 发现没有已退出的子进程可等待，则返回 0；
        3) 如果调用中出错，则返回-1，这时 errno 会被设置成相应的值以指示错误所在，如：当 pid 所对应的子进程不存在，或此进程存在，但不是调用进程的子进程，waitpid() 就会出错返回，这时 errno 被设置为 ECHILD；
```

## 4.6 孤儿进程、僵尸进程

**孤儿进程**

**父进程运行结束，但子进程还在运行（未运行结束）的子进程就称为孤儿进程**（Orphan Process）。

每当出现一个孤儿进程的时候，**内核就把孤儿进程的父进程设置为 init** ，而 init 进程会循环地 wait() 它的已经退出的子进程。这样，当一个孤儿进程凄凉地结束了其生命周期的时候，**init 进程就会代表党和政府出面处理它的一切善后工作**。因此孤儿进程并不会有什么危害。

 **僵尸进程**

**进程终止，父进程尚未回收，子进程残留资源（PCB）存放于内核中，变成僵尸（Zombie）进程**

这样就会导致一个问题，如果进程不调用wait() 或 waitpid() 的话， 那么保留的那段信息就不会释放，其进程号就会一直被占用，但是系统所能使用的进程号是有限的。**如果大量的产生僵尸进程，将因为没有可用的进程号而导致系统不能产生新的进程，此即为僵尸进程的危害，应当避免**

## 4.7 进程替换

**如果我们本来就运行着一个程序（进程），我们如何在这个进程内部启动一个外部程序，由内核将这个外部程序读入内存，使其执行起来成为一个进程呢？这里我们通过 exec 函数族实现。**

exec 函数族，顾名思义，就是一簇函数，在 Linux 中，并不存在 exec() 函数，exec 指的是一组函数，一共有 6 个：

```c
#include <unistd.h>
extern char **environ;

int execl(const char *path, const char *arg, .../* (char  *) NULL */);
	//arg0 arg1 arg2 ... argn
	//arg0一般是可执行文件路径，arg1为文件名，argn必须为NULL
int execlp(const char *file, const char *arg, ... /* (char  *) NULL */);
	//arg0 arg1 arg2 ... argn
	//arg0一般是可执行文件名，argn必须为NULL
//用前面两个即可，后面了解
int execle(const char *path, const char *arg, .../*, (char *) NULL, char * const envp[] */);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[], char *const envp[]);

int execve(const char *filename, char *const argv[], char *const envp[]);
```

其中只有 execve() 是真正意义上的系统调用，其它都是在此基础上经过包装的库函数。

exec 函数族的作用是根据指定的文件名或目录名找到可执行文件，并用它来取代调用进程的内容，换句话说，就是在调用进程内部执行一个可执行文件。

进程调用一种 exec 函数时，该进程完全由新程序替换，而新程序则从其 main 函数开始执行。因为调用 exec 并不创建新进程，所以前后的进程 ID （当然还有父进程号、进程组号、当前工作目录……）并未改变。exec 只是用另一个新程序替换了当前进程的正文、数据、堆和栈段（进程替换）。

```c
int main(){
	printf("hello itcast\n");
	//arg0 arg1 arg2 ... argn
	//arg0一般是可执行文件名，argn必须为NULL
	//等价执行 ls -l /home
	execlp("ls","ls","-l","/home",NULL);
	printf("hello world");
}
```

<img src="img\execlp执行结果.png" alt="execlp执行结果" style="zoom:67%;" />

<img src="img\exec原理.png" alt="exec原理" style="zoom:60%;" />

**exec 函数族使用说明**

exec 函数族的 6 个函数看起来似乎很复杂，但实际上无论是作用还是用法都非常相似，只有很微小的差别。

<img src="img\exec函数族.png" alt="exec函数族" style="zoom:80%;" />

补充说明：

| l(list)        | 参数地址列表，以空指针结尾               |
| :------------- | :--------------------------------------- |
| v(vector)      | 存有各参数地址的指针数组的地址           |
| p(path)        | 按 PATH 环境变量指定的目录搜索可执行文件 |
| e(environment) | 存有环境变量字符串地址的指针数组的地址   |

**exec 函数族中的函数执行成功后不会返回，而且，exec 函数族下面的代码执行不到**

**只有调用失败了，它们才会返回 -1，失败后从原程序的调用点接着往下执行**

# 5. 进程间通信

## 5.1 进程间通讯概念

进程是一个独立的资源分配单元，不同进程之间的资源是独立的，没有关联，不能在一个进程中直接访问另一个进程的资源。但是，进程不是孤立的，不同的进程需要进行信息的交互和状态的传递等，因此需要进程间通信( IPC：Inter Processes Communication )。

进程间通信的目的：数据传输、通知事件、资源共享、进程控制

**Linux 操作系统支持的主要进程间通信的通信机制：**

<img src="img\进程间通信.png" alt="进程间通信" style="zoom:75%;" />

## 5.2 无名管道

管道也叫无名管道，它是是 UNIX 系统 IPC（进程间通信） 的最古老形式，所有的 UNIX 系统都支持这种通信机制。

管道有如下特点：

1) **半双工**

3) 写入管道中的数据遵循**先入先出**的规则。

4) 管道所传送的数据是无格式的，这要求管道的读出方与写入方必须事先约定好数据的格式，如多少字节算一个消息等。

5) 管道不是普通的文件，不属于某个文件系统，其**只存在于内存中**

6) 管道在内存中对应一个缓冲区。不同的系统其大小不一定相同。

7) 从管道读数据是一次性操作，数据一旦被读走，它就从管道中被抛弃，释放空间以便写更多的数据。

8) 管道无名字，只能在具有**公共祖先的进程（父进程与子进程，或者两个兄弟进程，具有亲缘关系）之间使用**——因为共用文件描述符

管道是一种特殊类型的文件，在应用层体现为两个打开的文件描述符。

### pipe函数——创建管道

```c
#include <unistd.h>
int pipe(int pipefd[2]);
功能：创建无名管道。
参数：
    pipefd : 为 int 型数组的首地址，其存放了管道的文件描述符 pipefd[0]、pipefd[1]。    
    当一个管道建立时，它会创建两个文件描述符 fd[0] 和 fd[1]。其中 fd[0] 固定用于读管道，而 fd[1] 固定用于写管道。一般文件 I/O的函数都可以用来操作管道(lseek() 除外)。
返回值：
    成功：0
    失败：-1
```

例子，子进程通过无名管道给父进程传递一个字符串数据：

```c
int main()
{
    int fd_pipe[2] = {0};
    pid_t pid;
    if (pipe(fd_pipe)<0){// 创建管道
        perror("pipe");
    }

    pid = fork(); // 创建进程
    if (pid == 0)
    { // 子进程
        char buf[] = "I am mike";
        // 往管道写端写数据
        write(fd_pipe[1], buf, strlen(buf));
        exit(0);
    }
    else if (pid > 0)
    {// 父进程
        wait(NULL); // 等待子进程结束，回收其资源
        char str[50] = {0};
        // 从管道里读数据
        read(fd_pipe[0], str, sizeof(str));

        printf("str=[%s]\n", str); // 打印数据
    }
    return 0;
}
```

### 管道的读写特点

**读管道：**

> 管道中有数据，read返回实际读到的字节数

> 管道中无数据：
>
> ​		管道写端被全部关闭，read返回0 (相当于读到文件结尾)
>
> ​		写端没有全部被关闭，read阻塞等待(不久的将来可能有数据递达，此时会让出cpu)

**写管道：**

> 管道读端全部被关闭， 进程异常终止(也可使用捕捉SIGPIPE信号，使进程终止)

> 管道读端没有全部关闭：
>
> ​		管道已满，write阻塞。
>
> ​		管道未满，write将数据写入，并返回实际写入的字节数。

### 设置为非阻塞的方法

```c
//获取原来的flags
int flags = fcntl(fd[0], F_GETFL);
// 设置新的flags
flag |= O_NONBLOCK;
// flags = flags | O_NONBLOCK;
fcntl(fd[0], F_SETFL, flags);
```

如果写端没有关闭，读端设置为非阻塞， 如果没有数据，直接返回-1

### 查看管道缓冲区命令——ulimit -a

> ulimit -a	查看当前系统中创建管道文件所对应的内核缓冲区大小

pipe size	(512 bytes -p)	8	//管道缓冲区大小8*512b=4k

### 查看管道缓冲区函数——fpathconf

```c
#include <unistd.h>
long fpathconf(int fd, int name);
功能：该函数可以通过name参数查看不同的属性值
参数：
    fd：文件描述符，使用观点的读端或写端的文件描述符都可
    name：
        _PC_PIPE_BUF，查看管道缓冲区大小
        _PC_NAME_MAX，文件名字字节数的上限
返回值：
    成功：根据name返回的值的意义也不同。
    失败： -1
```

## 5.3 有名管道

管道，由于没有名字，只能用于亲缘关系的进程间通信。**为了克服这个缺点，提出了命名管道（FIFO）**，也叫有名管道、FIFO文件。

命名管道（FIFO）不同于无名管道之处在于它提供了一个路径名与之关联，以 FIFO 的文件形式存在于文件系统中，这样，即使与 FIFO 的创建进程不存在亲缘关系的进程，只要可以访问该路径，就能够彼此通过 FIFO 相互通信，因此，通过 FIFO 不相关的进程也能交换数据。

命名管道（FIFO)和无名管道（pipe）有一些特点是相同的，不一样的地方在于：

1) FIFO 在文件系统中作为一个特殊的文件而存在，但 FIFO 中的内容却存放在内存中。

2) **当使用 FIFO 的进程退出后，FIFO 文件将继续保存在文件系统中以便以后使用**。

3) FIFO 有名字，**不相关的进程可以通过打开命名管道进行通信**。

### 通过命令创建有名管道

> mkfifo 管道名

创建的管道会存储在当前目录下

### 通过函数创建有名管道——mkfifo()

```c
#include <sys/types.h>
#include <sys/stat.h>
int mkfifo(const char *pathname, mode_t mode);
功能：
    命名管道的创建。
参数：
    pathname : 普通的路径名，也就是创建后 FIFO 的名字。
    mode : 文件的权限，与打开普通文件的 open() 函数中的 mode 参数相同。(0666)
返回值：
    成功：0   状态码
    失败：如果文件已经存在，则会出错且返回 -1。
```

### 有名管道读写操作

一旦使用mkfifo创建了一个FIFO，就可以使用open打开它，常见的文件I/O函数都可用于fifo。如：close、read、write、unlink等。

FIFO严格遵循先进先出（first in first out），对管道及FIFO的读总是从开始处返回数据，对它们的写则把数据添加到末尾。**它们不支持诸如lseek()等文件定位操作。**

```c
//进行1，写操作
int fd = open("my_fifo", O_WRONLY);  

char send[100] = "Hello Mike";
write(fd, send, strlen(send));

//进程2，读操作
int fd = open("my_fifo", O_RDONLY);//等着只写  

char recv[100] = { 0 };
//读数据，命名管道没数据时会阻塞，有数据时就取出来  
read(fd, recv, sizeof(recv));
printf("read from my_fifo buf=[%s]\n", recv);
```

## 5.4 共享存储映射

存储映射I/O (Memory-mapped I/O) 使一个磁盘文件与存储空间中的一个缓冲区相映射

![共享存储](img\共享存储.png)

于是当从缓冲区中取数据，就相当于读文件中的相应字节。于此类似，将数据存入缓冲区，则相应的字节就自动写入文件。这样，就可在不适用read和write函数的情况下，使用地址（指针）完成I/O操作。

共享内存可以说是最有用的进程间通信方式，也是最快的IPC形式, 因为进程可以直接读写内存，而不需要任何数据的拷贝。

### 存储映射函数

**mmap函数**

```c
#include <sys/mman.h>
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
功能:
    一个文件或者其它对象映射进内存
参数：
    addr :  指定映射的起始地址, 通常设为NULL, 由系统指定
    length：映射到内存的文件长度
    prot：  映射区的保护方式, 最常用的 :
        a) 读：PROT_READ
        b) 写：PROT_WRITE
        c) 读写：PROT_READ | PROT_WRITE
    flags：  映射区的特性, 可以是
        a) MAP_SHARED : 写入映射区的数据会复制回文件, 且允许其他映射该文件的进程共享。
        b) MAP_PRIVATE : 对映射区的写入操作会产生一个映射区的复制(copy - on - write), 对此区域所做的修改不会写回原文件。
    fd：由open返回的文件描述符, 代表要映射的文件。
    offset：以文件开始处的偏移量, 必须是4k的整数倍, 通常为0, 表示从文件头开始映射
返回值：
    成功：返回创建的映射区首地址
    失败：MAP_FAILED宏
```

关于mmap函数的使用总结：

1) 第一个参数写成NULL

2) 第二个参数要映射的文件大小 > 0

3) 第三个参数：PROT_READ 、PROT_WRITE

4) 第四个参数：MAP_SHARED 或者 MAP_PRIVATE

5) 第五个参数：打开的文件对应的文件描述符

6) 第六个参数：4k的整数倍，通常为0

**munmap函数**

```c
#include <sys/mman.h>
int munmap(void *addr, size_t length);
功能：
    释放内存映射区
参数：
    addr：使用mmap函数创建的映射区的首地址
    length：映射区的大小
返回值：
    成功：0
    失败：-1
```

**注意：**

1) 创建映射区的过程中，隐含着一次对映射文件的读操作。

2) 当MAP_SHARED时，要求：映射区的权限应 <=文件打开的权限(出于对映射区的保护)。而MAP_PRIVATE则无所谓，因为mmap中的权限是对内存的限制。

3) 映射区的释放与文件关闭无关。只要映射建立成功，文件可以立即关闭。

4) 特别注意，当映射文件大小为0时，不能创建映射区。所以，用于映射的文件必须要有实际大小。mmap使用时常常会出现总线错误，通常是由于共享文件存储空间大小引起的。

5) munmap传入的地址一定是mmap的返回地址。坚决杜绝指针++操作。

6) 如果文件偏移量必须为4K的整数倍。

7) mmap创建映射区出错概率非常高，一定要检查返回值，确保映射区建立成功再进行后续操作。

### 共享映射的方式操作文件

```c
int fd = open("xxx.txt", O_RDWR); //读写文件
int len = lseek(fd, 0, SEEK_END);   //获取文件大小

//一个文件映射到内存，ptr指向此内存
void * ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
if (ptr == MAP_FAILED){
	perror("mmap error");
    exit(1);
}
close(fd); //关闭文件
char buf[4096];
printf("buf = %s\n", (char*)ptr); // 从内存中读数据，等价于从文件中读取内容
strcpy((char*)ptr, "this is a test");//写内容

int ret = munmap(ptr, len);
if (ret == -1){
    perror("munmap error");
    exit(1);
}
```

### 共享映射实现父子进程通信

```c
int fd = open("xxx.txt", O_RDWR);// 打开一个文件
int len = lseek(fd, 0, SEEK_END);//获取文件大小
// 创建内存映射区
void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
if (ptr == MAP_FAILED){
    perror("mmap error");
    exit(1);
}
close(fd); //关闭文件

// 创建子进程
pid_t pid = fork();
if (pid == 0){//子进程
    sleep(1); //演示，保证父进程先执行
    // 读数据
    printf("%s\n", (char*)ptr);
}
else if (pid > 0){//父进程
    // 写数据
    strcpy((char*)ptr, "i am u father!!");
    // 回收子进程资源
    wait(NULL);
}
// 释放内存映射区
int ret = munmap(ptr, len);
if (ret == -1){
    perror("munmap error");
    exit(1);
}
```

### 匿名映射实现父子进程通信

通过使用我们发现，使用映射区来完成文件读写操作十分方便，父子进程间通信也较容易。但缺陷是，每次创建映射区一定要依赖一个文件才能实现。

通常为了建立映射区要open一个temp文件，创建好了再unlink、close掉，比较麻烦。 可以直接使用匿名映射来代替。

其实Linux系统给我们提供了创建匿名映射区的方法，无需依赖一个文件即可创建映射区。同样需要借助标志位参数flags来指定。

使用**MAP_ANONYMOUS (或MAP_ANON)**。

```
int *p = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
```

- 4"随意举例，该位置表示映射区大小，可依实际需要填写。
- MAP_ANONYMOUS和MAP_ANON这两个宏是Linux操作系统特有的宏。在类Unix系统中如无该宏定义，可使用如下两步来完成匿名映射区的建立。

程序示例：

```c
// 创建匿名内存映射区
int len = 4096;
void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
if (ptr == MAP_FAILED){
    perror("mmap error");
    exit(1);
}
// 创建子进程
pid_t pid = fork();
if (pid > 0){//父进程
    // 写数据
    strcpy((char*)ptr, "hello mike!!");
    // 回收
    wait(NULL);
}
else if (pid == 0){//子进程
    sleep(1);
    // 读数据
    printf("%s\n", (char*)ptr);
}

// 释放内存映射区
int ret = munmap(ptr, len);
if (ret == -1){
    perror("munmap error");
    exit(1);
}
```

# 6. 信号

## 6.1 信号的概述

信号是 Linux 进程间通信的最古老的方式。**信号是软件中断**，它是在软件层次上对中断机制的一种模拟，是一种异步通信的方式 。**信号可以导致一个正在运行的进程被另一个正在运行的异步进程中断，转而处理某一个突发事件。**

###  信号的编号(了解)

1）信号编号：

查看信号编号: kill -l(字母)

![信号编号](img\信号编号.png)

不存在编号为0的信号。其中1-31号信号称之为常规信号（也叫普通信号或标准信号），34-64称之为实时信号，驱动编程与硬件相关。

Linux常规信号一览表 :

| **编号** | **信号**             | **对应事件**                                                 | **默认动作**               |
| :------- | :------------------- | :----------------------------------------------------------- | :------------------------- |
| 1        | SIGHUP               | 用户退出shell时，由该shell启动的所有进程将收到这个信号       | 终止进程                   |
| 2        | **SIGINT**           | 当用户按下了**<Ctrl+C>**组合键时，用户终端向正在运行中的由该终端启动的程序发出此信号 | 终止进程                   |
| 3        | **SIGQUIT**          | 用户按下**<ctrl+\\>**组合键时产生该信号，用户终端向正在运行中的由该终端启动的程序发出些信号 | 终止进程                   |
| 4        | SIGILL               | CPU检测到某进程执行了非法指令                                | 终止进程并产生core文件     |
| 5        | SIGTRAP              | 该信号由断点指令或其他 trap指令产生                          | 终止进程并产生core文件     |
| 6        | SIGABRT              | 调用abort函数时产生该信号                                    | 终止进程并产生core文件     |
| 7        | SIGBUS               | 非法访问内存地址，包括内存对齐出错                           | 终止进程并产生core文件     |
| 8        | SIGFPE               | 在发生致命的运算错误时发出。不仅包括浮点运算错误，还包括溢出及除数为0等所有的算法错误 | 终止进程并产生core文件     |
| 9        | SIGKILL              | 无条件终止进程。本信号不能被忽略，处理和阻塞                 | 终止进程，可以杀死任何进程 |
| 10       | SIGUSE1              | 用户定义的信号。即程序员可以在程序中定义并使用该信号         | 终止进程                   |
| 11       | **SIGSEGV**          | 指示进程进行了无效内存访问(段错误)                           | 终止进程并产生core文件     |
| 12       | SIGUSR2              | 另外一个用户自定义信号，程序员可以在程序中定义并使用该信号   | 终止进程                   |
| 13       | **SIGPIPE**          | Broken pipe向一个没有读端的管道写数据                        | 终止进程                   |
| 14       | SIGALRM              | 定时器超时，超时的时间 由系统调用alarm设置                   | 终止进程                   |
| 15       | SIGTERM              | 程序结束信号，与SIGKILL不同的是，该信号可以被阻塞和终止。通常用来要示程序正常退出。执行shell命令Kill时，缺省产生这个信号 | 终止进程                   |
| 16       | SIGSTKFLT            | Linux早期版本出现的信号，现仍保留向后兼容                    | 终止进程                   |
| 17       | **SIGCHLD**          | 子进程结束时，父进程会收到这个信号                           | 忽略这个信号               |
| 18       | SIGCONT              | 如果进程已停止，则使其继续运行                               | 继续/忽略                  |
| 19       | SIGSTOP              | 停止进程的执行。信号不能被忽略，处理和阻塞                   | 为终止进程                 |
| 20       | SIGTSTP              | 停止终端交互进程的运行。按下<ctrl+z>组合键时发出这个信号     | 暂停进程                   |
| 21       | SIGTTIN              | 后台进程读终端控制台                                         | 暂停进程                   |
| 22       | SIGTTOU              | 该信号类似于SIGTTIN，在后台进程要向终端输出数据时发生        | 暂停进程                   |
| 23       | SIGURG               | 套接字上有紧急数据时，向当前正在运行的进程发出些信号，报告有紧急数据到达。如网络带外数据到达 | 忽略该信号                 |
| 24       | SIGXCPU              | 进程执行时间超过了分配给该进程的CPU时间 ，系统产生该信号并发送给该进程 | 终止进程                   |
| 25       | SIGXFSZ              | 超过文件的最大长度设置                                       | 终止进程                   |
| 26       | SIGVTALRM            | 虚拟时钟超时时产生该信号。类似于SIGALRM，但是该信号只计算该进程占用CPU的使用时间 | 终止进程                   |
| 27       | SGIPROF              | 类似于SIGVTALRM，它不公包括该进程占用CPU时间还包括执行系统调用时间 | 终止进程                   |
| 28       | SIGWINCH             | 窗口变化大小时发出                                           | 忽略该信号                 |
| 29       | SIGIO                | 此信号向进程指示发出了一个异步IO事件                         | 忽略该信号                 |
| 30       | SIGPWR               | 关机                                                         | 终止进程                   |
| 31       | SIGSYS               | 无效的系统调用                                               | 终止进程并产生core文件     |
| 34~64    | SIGRTMIN ～ SIGRTMAX | LINUX的实时信号，它们没有固定的含义（可以由用户自定义）      | 终止进程                   |

### 信号四要素

1）编号 2）名称 3）事件 4）默认处理动作

可通过**man 7 signal**查看帮助文档获取：

<img src="img\信号四要素.png" alt="信号四要素" style="zoom:67%;" />



在标准信号中，有一些信号是有三个“Value”，第一个值通常对alpha和sparc架构有效，中间值针对x86、arm和其他架构，最后一个应用于mips架构。一个‘-’表示在对应架构上尚未定义该信号。**建议使用信号名(宏)，增强可移植性。**

Action为默认动作：

- Term：终止进程
- Ign： 忽略信号 (默认即时对该种信号忽略操作)
- Core：终止进程，生成Core文件。(查验死亡原因，用于gdb调试)
- Stop：停止（暂停）进程
- Cont：继续运行进程

注意通过man 7 signal命令查看帮助文档，其中可看到 : The signals **SIGKILL** and **SIGSTOP** cannot be caught, blocked, or ignored.

这里特别强调了**9) SIGKILL** **和19) SIGSTOP信号，不允许忽略和捕捉，只能执行默认动作。甚至不能将其设置为阻塞。**

### 信号的状态

**1) 产生**

a) 当用户按某些终端键时，将产生信号

终端上按“Ctrl+c”键通常产生中断信号 SIGINT、按“Ctrl+\”键通常产生中断信号 SIGQUIT、按“Ctrl+z”键通常产生中断信号 SIGSTOP 

b) 硬件异常将产生信号。

除数为 0，无效的内存访问等。这些情况通常由硬件检测到，并通知内核，然后内核产生适当的信号发送给相应的进程。

c) 软件异常将产生信号。

当检测到某种软件条件已发生(如：定时器alarm)，并将其通知有关进程时，产生信号。

d) 调用系统函数(如：kill、raise、abort)将发送信号。

e) 运行 kill /killall命令将发送信号。

**2) 未决状态：没有被处理**

**3) 递达状态：信号被处理了**

### 阻塞信号集和未决信号集

信号的实现手段导致信号有很强的延时性，但对于用户来说，时间非常短，不易察觉。

Linux内核的进程控制块PCB是一个结构体，task_struct, 除了包含进程id，状态，工作目录，用户id，组id，文件描述符表，还包含了信号相关的信息，主要指**阻塞信号集和未决信号集**。

**阻塞信号集(信号屏蔽字)**

将某些信号加入集合，对他们设置屏蔽，当屏蔽x信号后，再收到该信号，该信号的处理将推后(处理发生在解除屏蔽后)。

**未决信号集**

信号产生，未决信号集中描述该信号的位立刻翻转为1，表示信号处于未决状态。当信号被处理对应位翻转回为0。这一时刻往往非常短暂。信号产生后由于某些原因(主要是阻塞)不能抵达。这类信号的集合称之为未决信号集。在屏蔽解除前，信号一直处于未决状态。

## 6.2 信号产生函数

### kill函数

```c
#include <sys/types.h>
#include <signal.h>
int kill(pid_t pid, int sig);
功能：给指定进程发送指定信号(不一定杀死)

参数：
    pid : 取值有 4 种情况 :
        pid > 0:  将信号传送给进程 ID 为pid的进程。
        pid = 0 :  将信号传送给当前进程所在进程组中的所有进程。
        pid = -1 : 将信号传送给系统内所有的进程。
        pid < -1 : 将信号传给指定进程组的所有进程。这个进程组号等于 pid 的绝对值。
    sig : 信号的编号，这里可以填数字编号，也可以填信号的宏定义，可以通过命令 kill - l("l" 为字母)进行相应查看。不推荐直接使用数字，应使用宏名，因为不同操作系统信号编号可能不同，但名称一致。

返回值：
    成功：0
    失败：-1
```

super用户(root)可以发送信号给任意用户，普通用户是不能向系统用户发送信号的。

kill -9 (root用户的pid) 是不可以的。同样，普通用户也不能向其他普通用户发送信号，终止其进程。 只能向自己创建的进程发送信号。

普通用户基本规则是：发送者实际或有效用户ID == 接收者实际或有效用户ID

### raise函数

```c
#include <signal.h>
int raise(int sig);
功能：给当前进程发送指定信号(自己给自己发)，等价于 kill(getpid(), sig)
参数：
    sig：信号编号
返回值：
    成功：0
    失败：非0值
```

### abort函数

```c
#include <stdlib.h>
void abort(void);
功能：给自己发送异常终止信号 6) SIGABRT，并产生core文件，等价于kill(getpid(), SIGABRT);
参数：无
返回值：无
```

### alarm函数(闹钟)

```c
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
功能：
    设置定时器(闹钟)。在指定seconds后，内核会给当前进程发送14）SIGALRM信号。进程收到该信号，默认动作终止。每个进程都有且只有唯一的一个定时器。
    取消定时器alarm(0)，返回旧闹钟余下秒数。
参数：
    seconds：指定的时间，以秒为单位
返回值：
    返回0或剩余的秒数
```

定时，与进程状态无关(自然定时法)！就绪、运行、挂起(阻塞、暂停)、终止、僵尸……无论进程处于何种状态，alarm都计时。

### setitimer函数（定时器）

```c
#include <sys/time.h>
int setitimer(int which,  const struct itimerval *new_value, struct itimerval *old_value);
功能：
    设置定时器(闹钟)。 可代替alarm函数。精度微秒us，可以实现周期定时。
参数：
    which：指定定时方式
        a) 自然定时：ITIMER_REAL → 14）SIGALRM计算自然时间
        b) 虚拟空间计时(用户空间)：ITIMER_VIRTUAL → 26）SIGVTALRM  只计算进程占用cpu的时间
        c) 运行时计时(用户 + 内核)：ITIMER_PROF → 27）SIGPROF计算占用cpu及执行系统调用的时间
    new_value：struct itimerval, 负责设定timeout时间
        struct itimerval {
            struct timerval it_interval; // 闹钟触发周期
            struct timerval it_value;    // 闹钟触发时间
        };
        struct timeval {
            long tv_sec;            // 秒
            long tv_usec;           // 微秒
        }
        itimerval.it_value： 设定第一次执行function所延迟的秒数 
        itimerval.it_interval：  设定以后每几秒执行function

    old_value： 存放旧的timeout值，一般指定为NULL
返回值：
    成功：0
    失败：-1
```

## 6.3 信号集

在PCB中有两个非常重要的信号集。一个称之为“阻塞信号集”，另一个称之为“未决信号集”。

这两个信号集都是内核使用**位图机制**来实现的。但操作系统不允许我们直接对其进行位操作。而需自定义另外一个集合，借助信号集操作函数来对PCB中的这两个信号集进行修改。

**用户可以设置阻塞信号集，只能读未决信号集(不可设置)**

### 自定义信号集函数

为了方便对多个信号进行处理，一个用户进程常常需要对多个信号做出处理，在 Linux 系统中引入了信号集（信号的集合）。信号集是一个能表示多个信号的数据类型，**sigset_t set，set即一个信号集**。既然是一个集合，就需要对集合进行添加/删除等操作。

```c
#include <signal.h>  
int sigemptyset(sigset_t *set);       //将set集合置空
int sigfillset(sigset_t *set)；          //将所有信号加入set集合
int sigaddset(sigset_t *set, int signo);  //将signo信号加入到set集合
int sigdelset(sigset_t *set, int signo);   //从set集合中移除signo信号
int sigismember(const sigset_t *set, int signo); //判断信号是否存在
```

除sigismember外，其余操作函数中的set均为传出参数。sigset_t类型的本质是位图。但不应该直接使用位操作，而应该使用上述函数，保证跨系统操作有效。

示例：

```c
int main(){
    sigset_t set;   // 定义一个信号集变量
    int ret = 0;

    sigemptyset(&set); // 清空信号集的内容

    // 判断 SIGINT 是否在信号集 set 里
    // 在返回 1， 不在返回 0
    ret = sigismember(&set, SIGINT);
    if (ret == 0) {
        printf("SIGINT is not a member of set \nret = %d\n", ret);
    }

    sigaddset(&set, SIGINT); // 把 SIGINT 添加到信号集 set
    sigaddset(&set, SIGQUIT);// 把 SIGQUIT 添加到信号集 set

    // 判断 SIGINT 是否在信号集 set 里
    // 在返回 1， 不在返回 0
    ret = sigismember(&set, SIGINT);
    if (ret == 1) {
        printf("SIGINT is a member of set \nret = %d\n", ret);
    }

    sigdelset(&set, SIGQUIT); // 把 SIGQUIT 从信号集 set 移除

    // 判断 SIGQUIT 是否在信号集 set 里
    // 在返回 1， 不在返回 0
    ret = sigismember(&set, SIGQUIT);
    if (ret == 0){
        printf("SIGQUIT is not a member of set \nret = %d\n", ret);
    }
    return 0;
}
```

**阻塞信号集可设置可读，未决信号集只能读**

### sigprocmask函数——设置信号阻塞集

每个进程都有一个阻塞集，创建子进程时**子进程将继承父进程的阻塞集**。所谓阻塞并不是禁止传送信号, 而是暂缓信号的传送。若将被阻塞的信号从信号阻塞集中删除，且对应的信号在被阻塞时发生了，进程将会收到相应的信号。

sigprocmask() 修改当前的信号掩码来改变信号的阻塞集

**共三种修改方式，对应参数how**

```c
#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
功能：
    检查或修改信号阻塞集，根据 how 指定的方法对进程的阻塞集合进行修改，新的信号阻塞集由 set 指定，而原先的信号阻塞集合由 oldset 保存。

参数：
    how : 信号阻塞集合的修改方法，有 3 种情况：
        SIG_BLOCK：向信号阻塞集合中添加 set 信号集，新的信号掩码是set和旧信号掩码的并集。相当于 mask = mask|set。
        SIG_UNBLOCK：从信号阻塞集合中删除 set 信号集，从当前信号掩码中去除 set 中的信号。相当于 mask = mask & ~ set。
        SIG_SETMASK：将信号阻塞集合设为 set 信号集，相当于原来信号阻塞集的内容清空，然后按照 set 中的信号重新设置信号阻塞集。相当于mask = set。
    set : 要操作的信号集地址。
        若 set 为 NULL，则不改变信号阻塞集合，函数只把当前信号阻塞集合保存到 oldset 中。
    oldset : 保存原先信号阻塞集地址

返回值：
    成功：0，
    失败：-1，失败时错误代码只可能是 EINVAL，表示参数 how 不合法。
```

### sigpending函数——读未决信号集

```c
#include <signal.h>
int sigpending(sigset_t *set);
功能：读取当前进程的未决信号集
参数：
    set：未决信号集
返回值：
    成功：0
    失败：-1
```

**例子:信号集**

```c
#include<stdio.h>
#include <signal.h>
#include <stdlib.h>

void readset(sigset_t *set){
    int i;
    for (i = 1; i<32; ++i){
        if (sigismember(set, i)){
            printf("1");
        }
        else if (sigismember(set, i) == 0){
            printf("0");
        }
    }
    printf("\n");
}
int main(){
    //自定义信号集
    sigset_t myset, old;
    sigemptyset(&myset);//清空
    //添加要阻塞的信号
    sigaddset(&myset, SIGINT);//ctrl+c
    sigaddset(&myset, SIGQUIT);//ctrl+\
    sigaddset(&myset, SIGKILL);//-9	该信号不能被阻塞，无效
    //自定义信号集设置到内核中的阻塞信号集
    sigprocmask(SIG_BLOCK, &myset, &old);
    sigset_t pend;
    int i = 0;
    while (1){
        // 读内核中的未决信号集的状态
        sigpending(&pend);
        readset(&pend);
        sleep(1);
        i++;
        // 5s之后解除阻塞
        if (i > 5){
            // sigprocmask(SIG_UNBLOCK, &myset, NULL);
            sigprocmask(SIG_SETMASK, &old, NULL);
        }
    }
    return 0;
}
```

## 6.4 信号捕获

### 信号处理方式

一个进程收到一个信号的时候，可以用如下方法进行处理：

1）**执行系统默认动作**

对大多数信号来说，系统默认动作是用来终止该进程。

2）**忽略此信号(丢弃)**

接收到此信号后没有任何动作。

3）**执行自定义信号处理函数(捕获)**

用用户定义的信号处理函数处理该信号。

【注意】：SIGKILL 和 SIGSTOP 不能更改信号的处理方式，因为它们向用户提供了一种使进程终止的可靠方法。

### signal函数

```c
#include <signal.h>
typedef void(*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
功能：
    注册信号处理函数（不可用于 SIGKILL、SIGSTOP 信号），即确定收到信号后处理函数的入口地址。此函数不会阻塞。

参数：
    signum：信号的编号，这里可以填数字编号，也可以填信号的宏定义，可以通过命令 kill - l("l" 为字母)进行相应查看。
    handler : 取值有 3 种情况：
          SIG_IGN：忽略该信号
          SIG_DFL：执行系统默认动作
          信号处理函数名：自定义信号处理函数，如：func
          回调函数的定义如下：
            void func(int signo)
            {
                // signo 为触发的信号，为 signal() 第一个参数的值
            }

返回值：
    成功：第一次返回 NULL，下一次返回此信号上一次注册的信号处理函数的地址。如果需要使用此返回值，必须在前面先声明此函数指针的类型。
    失败：返回 SIG_ERR
```

该函数由ANSI定义，由于历史原因在不同版本的Unix和不同版本的Linux中可能有不同的行为。**因此应该尽量避免使用它，取而代之使用sigaction函数。**

例子：

```c
#include<stdio.h>
#include <signal.h>
#include <stdlib.h>
//信号处理函数
void signal_handler(int signo){
    if (signo == SIGINT){
        printf("recv SIGINT\n");
    }
    else if (signo == SIGQUIT){
        printf("recv SIGQUIT\n");
    }
}

int main(){
    printf("wait for SIGINT OR SIGQUIT\n");
    // 信号注册函数
    signal(SIGINT, signal_handler);//SIGINT: Ctrl+c.
    signal(SIGQUIT, signal_handler);//SIGQUIT: Ctrl+\.
    while(1);//不让程序结束
    return 0;
}
```

### sigaction函数

```c
#include <signal.h>
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
功能：
    检查或修改指定信号的设置（或同时执行这两种操作）。
参数：
    signum：要操作的信号。
    act：   要设置的对信号的新处理方式（传入参数）。
    oldact：原来对信号的处理方式（传出参数）。
    如果 act 指针非空，则要改变指定信号的处理方式（设置），如果 oldact 指针非空，则系统将此前指定信号的处理方式存入 oldact。
返回值：
    成功：0
    失败：-1
```

**struct sigaction结构体：**

```c
struct sigaction {
    void(*sa_handler)(int); //旧的信号处理函数指针,兼容signal()函数的信号处理函数void(*)(int),函数指针的参数要相同
    void(*sa_sigaction)(int, siginfo_t *, void *); //新的信号处理函数指针
    sigset_t   sa_mask;      //信号阻塞集
    int        sa_flags;     //信号处理的方式
    void(*sa_restorer)(void); //已弃用
};

参数：
sa_handler、sa_sigaction：信号处理函数指针
    与 signal() 里的函数指针相同，根据情况给sa_sigaction、sa_handler 两者之一赋值，sa_handler、sa_sigaction取值如下：
    a) SIG_IGN：忽略该信号
    b) SIG_DFL：执行系统默认动作
	c) 处理函数名：自定义信号处理函数

sa_mask：信号阻塞集
    在信号处理函数执行过程中，临时屏蔽指定的信号

sa_flags：用于指定信号处理的行为，
    通常设置为0，表使用默认属性，使用sa_handler函数指针处理信号，其他设置如下：
    SA_RESTART：使被信号打断的系统调用自动重新发起（已经废弃）
    SA_NOCLDSTOP：使父进程在它的子进程暂停或继续运行时不会收到 SIGCHLD 信号。
    SA_NOCLDWAIT：使父进程在它的子进程退出时不会收到 SIGCHLD 信号，这时子进程如果退出也不会成为僵尸进程。
    SA_NODEFER：使对信号的屏蔽无效，即在信号处理函数执行期间仍能发出这个信号。
    SA_RESETHAND：信号处理之后重新设置为默认的处理方式。
    SA_SIGINFO：使用 sa_sigaction 成员而不是 sa_handler 作为信号处理函数。
```

**信号处理函数:**

```c
void(*sa_sigaction)(int signum, siginfo_t *info, void *context);
参数说明：
    signum：信号的编号。
    info：记录信号发送进程信息的结构体。
    context：可以赋给指向 ucontext_t 类型的一个对象的指针，以引用在传递信号时被中断的接收进程或线程的上下文。
```

**不需要传递更多的信息时，sa_flags设置为0，使用sa_handler函数指针处理信号(推荐)**

例子：

```c
#include<stdio.h>
#include <signal.h>
#include <stdlib.h>
//sigaction()信号捕获
void myfunc(int signo){
    printf("捕获 SIGINT：%d\n",signo);
}

int main(){
    printf("wait for SIGINT OR SIGQUIT\n");
    // 信号注册函数
    struct sigaction act;
    act.sa_flags = 0;
    act.sa_handler = myfunc;
    sigemptyset(&act.sa_mask);//清空阻塞
    //并不是进程阻塞ctrl+反斜杠，而是在捕获ctrl+c的过程中阻塞ctrl+反斜杠
    sigaddset(&act.sa_mask, SIGQUIT);//添加阻塞crtl+反斜杠
    sigaction(SIGINT, &act, NULL);//捕获SIGINT: Ctrl+c.
    while(1);//不让程序结束
    return 0;
}
```

### sigqueue 函数(了解)

```c
#include <signal.h>
int sigqueue(pid_t pid, int sig, const union sigval value);
功能：
    给指定进程发送信号。
参数：
    pid : 进程号。
    sig : 信号的编号。
    value : 通过信号传递的参数。
        union sigval 类型如下：
            union sigval
            {
                int   sival_int;
                void *sival_ptr;
            };
返回值：
    成功：0
    失败：-1
```

向指定进程发送指定信号的同时，携带数据。但如传地址，需注意，不同进程之间虚拟地址空间各自独立，将当前进程地址传递给另一进程没有实际意义。

## 6.5 不可重入、可重入函数

如果有一个函数被设计成：**不同任务调用这个函数时可能修改其他任务调用这个函数的数据，而导致不可预料的后果**。这样的函数是不**安全的函数，也叫不可重入函数**。

满足下列条件的函数多数是不可重入（不安全）的：

- 函数体内使用了静态的数据结构；
- 函数体内调用了malloc() 或者 free() 函数(谨慎使用堆)；
- 函数体内调用了标准 I/O 函数。

 相反，肯定有一个安全的函数，这个安全的函数又叫可重入函数。那么什么是可重入函数呢？所谓可重入是指一个可以被多个任务调用的过程，任务在调用时不必担心数据是否会出错。

 保证函数的可重入性的方法：

- 在写函数时候尽量**使用局部变量**（例如寄存器、栈中的变量）；
- 对于要使用的**全局变量要加以保护**（如采取关中断、信号量等互斥方法），这样构成的函数就一定是一个可重入的函数。

**注意：信号处理函数应该为可重入函数。**

## 6.6 SIGCHLD信号

### SIGCHLD信号产生的条件

1\) 子进程终止时

2\) 子进程接收到SIGSTOP信号停止时

3\) 子进程处在停止态，接受到SIGCONT后唤醒时

### 如何避免僵尸进程

1\) 最简单的方法，父进程通过 **wait() 和 waitpid() 等函数等待子进程结束回收其资源**，但是，这会导致父进程挂起。

2\) 如果父进程要处理的事情很多，不能够挂起，通过 signal() 函数人为处理信号 SIGCHLD ， 只要有子进程退出自动调用**指定好的信号处理函数回收资源**，因为子进程结束后， 父进程会收到该信号 SIGCHLD ，可以在其回调函数里调用 wait() 或 waitpid() 回收。

```c
void sig_child(int signo){
    pid_t  pid;
    //处理僵尸进程, -1 代表等待任意一个子进程, WNOHANG代表不阻塞
    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0){
        printf("child %d terminated.\n", pid);
    }
}
```

3\)如果父进程不关心子进程什么时候结束，那么可以用signal（SIGCHLD, SIG_IGN）通知内核，自己对子进程的结束不感兴趣，**父进程忽略此信号**，那么子进程结束后，**内核会回收**， 并不再给父进程发送信号。

```c
// 忽略子进程退出信号的信号
// 那么子进程结束后，内核会回收，并不再给父进程发送信号
signal(SIGCHLD, SIG_IGN);
```

# 7. 守护进程

## 7.1 终端、进程组、会话

### 终端(了解)

在UNIX系统中，用户通过终端登录系统后得到一个Shell进程，这个终端成为Shell进程的控制终端（Controlling Terminal），进程中，控制终端是保存在PCB中的信息，而fork会复制PCB中的信息，因此**由Shell进程启动的其它进程的控制终端也是这个终端**。

默认情况下（没有重定向），每个进程的标准输入、标准输出和标准错误输出都指向控制终端，进程从标准输入读也就是读用户的键盘输入，进程往标准输出或标准错误输出写也就是输出到显示器上。

> tty	//查询终端名

相关函数：

```c
#include <unistd.h>
char *ttyname(int fd);
功能：由文件描述符查出对应的文件名
参数：
    fd：文件描述符
返回值：
    成功：终端名
    失败：NULL
```

下面我们借助ttyname函数，通过实验看一下各种不同的终端所对应的设备文件名：

```c
int main(){
    printf("fd 0: %s\n", ttyname(0));
    printf("fd 1: %s\n", ttyname(1));
    printf("fd 2: %s\n", ttyname(2));

    return 0;
}
```

### 进程组(PGID)(理解)

进程组，也称之为作业。BSD于1980年前后向Unix中增加的一个新特性。**代表一个或多个进程的集合。**

每个进程都属于一个进程组。在waitpid函数和kill函数的参数中都曾使用到。操作系统设计的进程组的概念，是为了简化对多个进程的管理。当父进程，创建子进程的时候，默认子进程与父进程属于同一进程组。进程组ID为第一个进程ID(组长进程)。所以，组长进程标识：其进程组ID为其进程ID，可以使用**kill -SIGKILL -进程组ID**(负的)来将整个进程组内的进程全部杀死。

进程组生存期：进程组创建到最后一个进程离开(终止或转移到另一个进程组)。

一个进程可以为自己或子进程设置进程组ID。

相关函数：

```c
#include <unistd.h>
pid_t getpgrp(void);                 /* POSIX.1 version */
功能：获取当前进程的进程组ID
参数：无
返回值：总是返回调用者的进程组ID

pid_t getpgid(pid_t pid);
功能：获取指定进程的进程组ID
参数：
    pid：进程号，如果pid = 0，那么该函数作用和getpgrp一样
返回值：
    成功：进程组ID
    失败：-1

int setpgid(pid_t pid, pid_t pgid);
功能：
    改变进程默认所属的进程组。通常可用来加入一个现有的进程组或创建一个新进程组。
参数：
    将参1对应的进程，加入参2对应的进程组中
返回值：
    成功：0
    失败：-1
```

### 会话(了解)

**会话是一个或多个进程组的集合**

- 一个会话可以有一个控制终端。这通常是终端设备或**伪终端设备**；
- 建立与控制终端连接的会话首进程被称为控制进程；
- 一个会话中的几个进程组可被分为一个前台进程组以及一个或多个后台进程组；
- 如果一个会话有一个控制终端，则它有一个前台进程组，其它进程组为后台进程组；
- 如果终端接口检测到断开连接，则将挂断信号发送至控制进程（会话首进程）。

**创建会话注意事项**

1\) 调用进程不能是进程组组长，该进程变成新会话首进程(session header)

2\) 该调用进程是组长进程，则出错返回

3\) 该进程成为一个新进程组的组长进程

4\) 需有root权限(ubuntu不需要)

5\) **新会话丢弃原有的控制终端，该会话没有控制终端**

6\) 建立新会话时，先调用fork, 父进程终止，子进程调用setsid

**API函数介绍**

getsid函数：

```c
#include <unistd.h>
pid_t getsid(pid_t pid);
功能：获取进程所属的会话ID
参数：
    pid：进程号，pid为0表示查看当前进程session ID
返回值：
    成功：返回调用进程的会话ID
    失败：-1
```

组长进程不能成为新会话首进程，新会话首进程必定会成为组长进程。

setsid函数：

```c
#include <unistd.h>
pid_t setsid(void);
功能：
    创建一个会话，并以自己的ID设置进程组ID，同时也是新会话的ID。调用了setsid函数的进程，既是新的会长，也是新的组长。
参数：无
返回值：
    成功：返回调用进程的会话ID
    失败：-1
```

## 7.2 守护进程(重点)

### 守护进程介绍

守护进程（Daemon Process），也就是通常说的 Daemon 进程（精灵进程），是 Linux 中的后台服务进程。它是一个生存期较长的进程，通常独立于控制终端并且周期性地执行某种任务或等待处理某些发生的事件。一般采用以d结尾的名字。

**守护进程是个特殊的孤儿进程**，这种进程**脱离终端**，为什么要脱离终端呢？之所以脱离于终端是**为了避免进程被任何终端所产生的信息所打断，其在执行过程中的信息也不在任何终端上显示**。由于在 Linux 中，每一个系统与用户进行交流的界面称为终端，每一个从此终端开始运行的进程都会依附于这个终端，这个终端就称为这些进程的控制终端，当控制终端被关闭时，相应的进程都会自动关闭。

**Linux 的大多数服务器就是用守护进程实现的**。比如，Internet 服务器 inetd，Web 服务器 httpd 等。

### 守护进程模型

1\) 创建子进程，父进程退出(必须)

- 所有工作在子进程中进行形式上脱离了控制终端

2\) 在子进程中创建新会话(必须)

- setsid()函数
- 使子进程完全独立出来，脱离控制

3\) 改变当前目录为根目录(不是必须)

- chdir()函数
- 防止占用可卸载的文件系统
- 也可以换成其它路径

4\) 重设文件权限掩码(不是必须)

- umask()函数
- 防止继承的文件创建屏蔽字拒绝某些权限
- 增加守护进程灵活性

5\) 关闭文件描述符(不是必须)

- 通常关闭标准正确、错误输出，使其不在终端显示
- 继承的打开文件不会用到，浪费系统资源，无法卸载

6\) 开始执行守护进程核心工作(必须)

### 5.3 守护进程参考代码

写一个守护进程, 每隔2s获取一次系统时间, 将这个时间写入到磁盘文件：

```c
void dowork(){...}

int main(){
    pid_t pid = fork();
    if (pid == -1){
        perror("fork error");
        exit(1);
    }

    if (pid > 0){
        // 父进程退出
        exit(1);
    }
    else if (pid == 0){
        // 子进程
        // 提升为会长，同时也是新进程组的组长
        setsid();

        // 更改进程的执行目录
        chdir("/home/edu");

        // 更改掩码
        umask(0022);

        // 关闭文件描述符
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

       	//工作
        dowork();
        
        // 防止子进程退出
        while (1);
    }
    return 0;
}
```

# 8. 线程

## 8.1 基础

> 进程是操作系统分配资源的最小单位
>
> 线程是操作系统调度的最小单位

为了让进程完成一定的工作，**进程必须至少包含一个线程**。

<img src="img\线程资源共享.png" alt="线程资源共享" style="zoom:67%;" />

Linux 最初开发时，内核中并不能真正支持线程。但是它的确可以通过 clone() 系统调用将进程作为可调度的实体。改进 LinuxThreads，非常明显我们需要内核的支持，并且需要重写**线程库**。 IBM 的开发人员的团队开展了 NGPT（Next-Generation POSIX Threads）项目

进程和线程关系密切：

1\) 线程是轻量级进程(light-weight process)，也有PCB，创建线程使用的底层函数和进程一样，都是clone

2\) 从内核里看进程和线程是一样的，都有各自不同的PCB.

3\) 进程可以蜕变成线程

4\) 在linux下，线程最是小的执行单位；进程是最小的分配资源单位

查看指定进程的LWP号：

> ps  -Lf  pid

实际上，无论是创建进程的fork，还是创建线程的pthread_create，底层实现都是调用同一个内核函数 clone 。

Ø 如果复制对方的地址空间，那么就产出一个“进程”；

Ø 如果共享对方的地址空间，就产生一个“线程”。

Linux内核是不区分进程和线程的, 只在用户层面上进行区分。所以，线程所有操作函数 pthread_* 是库函数，而非系统调用。

### 线程资源

 **线程共享资源**

1\) 文件描述符表；2\) 每种信号的处理方式；3\) 当前工作目录；4\) 用户ID和组ID

内存地址空间 (.text/.data/.bss/heap/共享库)

**线程非共享资源**

1\) 线程id；2\) 处理器现场和栈指针(内核栈)；3\) 独立的栈空间(用户空间栈)；4\) errno变量；5\) 信号屏蔽字；6\) 调度优先级

### 线程的优缺点

**优点：**

提高程序并发性；开销小；数据通信、共享数据方便

**缺点：**

库函数，不稳定；调试、编写困难、gdb不支持；对信号支持不好

优点相对突出，缺点均不是硬伤。Linux下由于实现方法导致进程、线程差别不是很大。

## 8.2 线程常用操作

### 线程号

每个线程也有一个线程号。**进程号在整个系统中是唯一的，但线程号不同，线程号只在它所属的进程环境中有效。**

进程号用 pid_t 数据类型表示，是一个非负整数。线程号则用 pthread_t 数据类型来表示，Linux 使用无符号长整数表示。有的系统在实现pthread_t 的时候，用一个结构体来表示，所以在可移植的操作系统实现不能把它做为整数处理。

**pthread_self函数：**

```c
#include <pthread.h>
pthread_t pthread_self(void);
功能：
    获取线程号。
参数：
    无
返回值：
    调用线程的线程 ID 。
```

**pthread_equal函数:**

```c
int pthread_equal(pthread_t t1, pthread_t t2);
功能：
    判断线程号 t1 和 t2 是否相等。为了方便移植，尽量使用函数来比较线程 ID。
参数：
    t1，t2：待判断的线程号。
返回值：
    相等：  非 0
    不相等：0
```

线程函数的程序在 pthread 库中，故**gcc编译链接时要加上参数 -lpthread**

### 线程创建

**pthread_create函数：**

```c
#include <pthread.h>
int pthread_create(pthread_t *thread,
            const pthread_attr_t *attr,
            void *(*start_routine)(void *),
            void *arg );
功能：
    创建一个线程。
参数：
    thread：线程标识符地址。
    attr：线程属性结构体地址，通常设置为 NULL。
    start_routine：线程函数的入口地址。
    arg：传给线程函数的参数。
返回值：
    成功：0
    失败：非 0
```

**在一个线程中调用pthread_create()创建新的线程后，当前线程从pthread_create()返回继续往下执行，而新的线程所执行的代码由我们传给pthread_create的函数指针start_routine决定。**

由于pthread_create的错误码不保存在errno中，因此不能直接用perror()打印错误信息，可以先用strerror()把错误码转换成错误信息再打印。

```c
// 线程函数、回调函数
void *thread_fun(void * arg){
    sleep(1);
    int num = *((int *)arg);
    printf("int the new thread: num = %d\n", num);
    return NULL;
}

int main(){
    pthread_t tid;
    int test = 100;

    // 返回错误号
    int ret = pthread_create(&tid, NULL, thread_fun, (void *)&test);
    if (ret != 0){
        printf("error number: %d\n", ret);
        // 根据错误号打印错误信息
        printf("error information: %s\n", strerror(ret));
    }
    while (1);
    return 0;
}
```



### 线程资源回收

**pthread_join函数：**

```c
#include <pthread.h>
int pthread_join(pthread_t thread, void **retval);
功能：
    等待线程结束（此函数会阻塞），并回收线程资源，类似进程的 wait() 函数。如果线程已经结束，那么该函数会立即返回。
参数：
    thread：被等待的线程号。
    retval：用来存储线程退出状态的指针的地址。
返回值：
    成功：0
    失败：非 0
```

参考程序

```c
void *thead(void *arg){
    static int num = 123; //静态变量
    printf("after 2 seceonds, thread will return\n");
    sleep(2);
    return &num;
}

int main(){
    pthread_t tid;
    int ret = 0;
    void *value = NULL;

    // 创建线程
    pthread_create(&tid, NULL, thead, NULL);

    // 等待线程号为 tid 的线程，如果此线程结束就回收其资源
    // &value保存线程退出的返回值
    pthread_join(tid, &value);
    printf("value = %d\n", *((int *)value));
    return 0;
}
```

调用该函数的线程将挂起等待，直到id为thread的线程终止。thread线程以不同的方法终止，通过pthread_join得到的终止状态是不同的，总结如下：

1\) 如果thread线程通过return返回，retval所指向的单元里存放的是thread线程函数的返回值。

2\) 如果thread线程被别的线程调用pthread_cancel异常终止掉，retval所指向的单元里存放的是常数PTHREAD_CANCELED。

3\) 如果thread线程是自己调用pthread_exit终止的，retval所指向的单元存放的是传给pthread_exit的参数。

### 线程分离

**一般情况下，线程终止后，其终止状态一直保留到其它线程调用pthread_join获取它的状态为止。但是线程也可以被置为detach状态，这样的线程一旦终止就立刻回收它占用的所有资源，而不保留终止状态。**

不能对一个已经处于detach状态的线程调用pthread_join，这样的调用将返回EINVAL错误。也就是说，如果已经对一个线程调用了pthread_detach就不能再调用pthread_join了。**分离后不代表此线程不依赖与当前进程，线程分离的目的是将线程资源的回收工作交由系统自动来完成，也就是说当被分离的线程结束之后，系统会自动回收它的资源。但该线程对应的进程终止了，该线程也会终止。**

**pthread_detach函数：**

```c
#include <pthread.h>
int pthread_detach(pthread_t thread);
功能：
    使调用线程与当前进程分离，分离后不代表此线程不依赖与当前进程，线程分离的目的是将线程资源的回收工作交由系统自动来完成，也就是说当被分离的线程结束之后，系统会自动回收它的资源。所以，此函数不会阻塞。
参数：
    thread：线程号。
返回值：
    成功：0
    失败：非0
```

### 线程退出

在进程中我们可以调用exit函数或_exit函数来结束进程，在一个线程中我们可以通过以下三种在不终止整个进程的情况下停止它的控制流。

- 线程从执行函数中返回。
- 线程调用pthread_exit退出线程。
- 线程可以被同一进程中的其它线程取消。

**pthread_exit函数：**

```c
#include <pthread.h>
void pthread_exit(void *retval);
功能：
    退出调用线程。一个进程中的多个线程是共享该进程的数据段，因此，通常线程退出后所占用的资源并不会释放。
参数：
    retval：存储线程退出状态的指针。
返回值：无  
```

参考程序

```c
void *thread(void *arg){
    static int num = 123; //静态变量
    int i = 0;
    while (1){
        printf("I am runing\n");
        sleep(1);
        i++;
        if (i == 3){
            pthread_exit((void *)&num);
            // return &num;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]){
    int ret = 0;
    pthread_t tid;
    void *value = NULL;
    pthread_create(&tid, NULL, thread, NULL);
    pthread_join(tid, &value);
    printf("value = %d\n", *(int *)value);
    return 0;
}
```



### 线程取消

```c
#include <pthread.h>
int pthread_cancel(pthread_t thread);
功能：
    杀死(取消)线程
参数：
    thread : 目标线程ID。
返回值：
    成功：0
    失败：出错编号
```

注意：线程的取消并不是实时的，而又一定的延时。需要等待线程到达某个取消点(检查点)。类似于玩游戏存档，必须到达指定的场所(存档点，如：客栈、仓库、城里等)才能存储进度。杀死线程也不是立刻就能完成，必须要到达取消点。

取消点：是线程检查是否被取消，并按请求进行动作的一个位置。通常是一些系统调用creat，open，pause，close，read，write..... 执行命令**man 7 pthreads**可以查看具备这些取消点的系统调用列表。

可粗略认为一个系统调用(进入内核)即为一个取消点。

参考程序:

```c
void *thread_cancel(void *arg){
    while (1){
        pthread_testcancel(); //设置取消点
    }
    return NULL;
}

int main(){
    pthread_t tid;
    pthread_create(&tid, NULL, thread_cancel, NULL); //创建线程
    sleep(3);//3秒后
    pthread_cancel(tid); //取消tid线程
    pthread_join(tid, NULL);
    return 0;
}
```

# 9. 线程同步

## 互斥锁

**互斥：**一个公共资源同一时刻只能被一个进程或线程使用，多个进程或线程不能同时使用公共资源。

**同步：**两个或两个以上的进程或线程在运行过程中协同步调，按预定的先后次序运行。比如 A 任务的运行依赖于 B 任务产生的数据，或先后访问公共资源。

显然，同步是一种更为复杂的互斥，而互斥是一种特殊的同步。也就是说互斥是两个任务之间不可以同时运行，他们会相互排斥，必须等待一个线程运行完毕，另一个才能运行，而同步也是不能同时运行，但他是必须要按照某种次序来运行相应的线程（也是一种互斥）！因此互斥具有唯一性和排它性，但互斥并不限制任务的运行顺序，即任务是无序的，而同步的任务之间则有顺序关系。

### 互斥锁Mutex

而在线程里也有这么一把锁：互斥锁（mutex），也叫互斥量，互斥锁是一种简单的加锁的方法来控制对共享资源的访问，互斥锁只有两种状态,即**加锁**( lock )和**解锁**( unlock )。

互斥锁的操作流程如下：

1）在访问共享资源后临界区域前，对互斥锁进行加锁。

2）在访问完成后释放互斥锁导上的锁。

3）对互斥锁进行加锁后，任何其他试图再次对互斥锁加锁的线程将会被阻塞，直到锁被释放。

互斥锁的数据类型是： pthread_mutex_t。

### **pthread_mutex_init** 函数——初始化互斥锁

```c
#include <pthread.h>
int pthread_mutex_init(pthread_mutex_t *restrict mutex,
    const pthread_mutexattr_t *restrict attr);
功能：
    初始化一个互斥锁。
参数：
    mutex：互斥锁地址。类型是 pthread_mutex_t 。
    attr：设置互斥量的属性，通常可采用默认属性，即可将 attr 设为 NULL。

    可以使用宏 PTHREAD_MUTEX_INITIALIZER 静态初始化互斥锁，比如：
    pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;

这种方法等价于使用 NULL 指定的 attr 参数调用 pthread_mutex_init() 来完成动态初始化，不同之处在于 PTHREAD_MUTEX_INITIALIZER 宏不进行错误检查。

返回值：
    成功：0，成功申请的锁默认是打开的。
    失败：非 0 错误码
```

> restrict，C语言中的一种类型[限定符](https://baike.baidu.com/item/限定符/1924249)（Type Qualifiers），用于告诉编译器，对象已经被指针所引用，不能通过除该指针外所有其他直接或间接的方式修改该对象的内容。

### pthread_mutex_destroy函数——销毁互斥锁

```c
#include <pthread.h>
int pthread_mutex_destroy(pthread_mutex_t *mutex);
功能：
    销毁指定的一个互斥锁。互斥锁在使用完毕后，必须要对互斥锁进行销毁，以释放资源。
参数：
    mutex：互斥锁地址。
返回值：
    成功：0
    失败：非 0 错误码
```

### pthread_mutex_lock函数——上锁

```c
#include <pthread.h>
int pthread_mutex_lock(pthread_mutex_t *mutex);
功能：
    对互斥锁上锁，若互斥锁已经上锁，则调用者阻塞，直到互斥锁解锁后再上锁。
参数：
    mutex：互斥锁地址。
返回值：
    成功：0
    失败：非 0 错误码

int pthread_mutex_trylock(pthread_mutex_t *mutex);
	调用该函数时，若互斥锁未加锁，则上锁，返回 0；
	若互斥锁已加锁，则函数直接返回失败，即 EBUSY。
```

### pthread_mutex_unlock函数——解锁

```c
#include <pthread.h>
int pthread_mutex_unlock(pthread_mutex_t *mutex);
功能：
    对指定的互斥锁解锁。
参数：
    mutex：互斥锁地址。
返回值：
    成功：0
    失败：非0错误码
```

### 死锁（DeadLock）

**1）什么是死锁**

死锁是指两个或两个以上的进程在执行过程中，由于竞争资源或者由于彼此通信而造成的一种阻塞的现象，若无外力作用，它们都将无法推进下去。此时称系统处于死锁状态或系统产生了死锁，这些永远在互相等待的进程称为死锁进程。

**2）死锁引起的原因**

竞争不可抢占资源引起死锁

也就是我们说的第一种情况，而这都在等待对方占有的不可抢占的资源。

竞争可消耗资源引起死锁

有p1，p2，p3三个进程，p1向p2发送消息并接受p3发送的消息，p2向p3发送消息并接受p1的消息，p3向p1发送消息并接受p2的消息，如果设置是先接到消息后发送消息，则所有的消息都不能发送，这就造成死锁。

进程推进顺序不当引起死锁

有进程p1，p2，都需要资源A，B，本来可以p1运行A --> p1运行B --> p2运行A --> p2运行B，但是顺序换了，p1运行A时p2运行B，容易发生第一种死锁。互相抢占资源。

**3）死锁的必要条件**

**互斥条件**：某资源只能被一个进程使用，其他进程请求该资源时，只能等待，直到资源使用完毕后释放资源。

**请求和保持条件**：程序已经保持了至少一个资源，但是又提出了新要求，而这个资源被其他进程占用，自己占用资源却保持不放。

**不可抢占条件**：进程已获得的资源没有使用完，不能被抢占。

**循环等待条件**：必然存在一个循环链。

**4）处理死锁的思路**

**预防死锁**：破坏死锁的四个必要条件中的一个或多个来预防死锁。

**避免死锁**：和预防死锁的区别就是，在资源动态分配过程中，用某种方式防止系统进入不安全的状态。

**检测死锁**：运行时出现死锁，能及时发现死锁，把程序解脱出来

**解除死锁**：发生死锁后，解脱进程，通常撤销进程，回收资源，再分配给正处于阻塞状态的进程。

**5）预防死锁的方法**

**破坏请求和保持条件**

协议1：

所有进程开始前，**必须一次性地申请所需的所有资源**，这样运行期间就不会再提出资源要求，破坏了请求条件，即使有一种资源不能满足需求，也不会给它分配正在空闲的资源，这样它就没有资源，就破坏了保持条件，从而预防死锁的发生。

协议2：

允许一个进程只获得初期的资源就开始运行，然后再把运行完的资源释放出来。然后再请求新的资源。

**破坏不可抢占条件**

当一个已经保持了某种不可抢占资源的进程，提出新资源请求不能被满足时，它必须释放已经保持的所有资源，以后需要时再重新申请。

**破坏循环等待条件**

对系统中的所有资源类型进行线性排序，然后规定每个进程必须按序列号递增的顺序请求资源。假如进程请求到了一些序列号较高的资源，然后有请求一个序列较低的资源时，必须先释放相同和更高序号的资源后才能申请低序号的资源。多个同类资源必须一起请求。

### 程序示例_互斥锁：

```c
pthread_mutex_t mutex; //互斥锁

// 打印机
void printer(char *str){
    pthread_mutex_lock(&mutex); //上锁
    while (*str != '\0')
    {
        putchar(*str);
        fflush(stdout);
        str++;
        sleep(1);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex); //解锁
}

// 线程一
void *thread_fun_1(void *arg){
    char *str = "hello";
    printer(str); //打印
}

// 线程二
void *thread_fun_2(void *arg){
    char *str = "world";
    printer(str); //打印
}

int main(void){    
    pthread_mutex_init(&mutex, NULL); //初始化互斥锁

    // 创建 2 个线程
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread_fun_1, NULL);
    pthread_create(&tid2, NULL, thread_fun_2, NULL);

    // 等待线程结束，回收其资源
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&mutex); //销毁互斥锁
    return 0;
}
```

## 读写锁

对数据的读写操作中，更多的是读操作，写操作较少，例如对数据库数据的读写应用。为了满足当前能够允许多个读出，但只允许一个写入的需求，线程提供了**读写锁**来实现。**可同时读，不可同时写，不可同时读写**

POSIX 定义的读写锁的数据类型是： pthread_rwlock_t

### pthread_rwlock_init函数——初始化读写锁

```c
#include <pthread.h>
int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock,
    const pthread_rwlockattr_t *restrict attr);
功能：
    用来初始化 rwlock 所指向的读写锁。

参数：
    rwlock：指向要初始化的读写锁指针。
    attr：读写锁的属性指针。如果 attr 为 NULL 则会使用默认的属性初始化读写锁，否则使用指定的 attr 初始化读写锁。

    可以使用宏 PTHREAD_RWLOCK_INITIALIZER 静态初始化读写锁，比如：
    pthread_rwlock_t my_rwlock = PTHREAD_RWLOCK_INITIALIZER;

    这种方法等价于使用 NULL 指定的 attr 参数调用 pthread_rwlock_init() 来完成动态初始化，不同之处在于PTHREAD_RWLOCK_INITIALIZER 宏不进行错误检查。

返回值：
    成功：0，读写锁的状态将成为已初始化和已解锁。
    失败：非 0 错误码。
```

### pthread_rwlock_destroy函数——销毁一个读写锁

```c
#include <pthread.h>
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
功能：
    用于销毁一个读写锁，并释放所有相关联的资源（所谓的所有指的是由 pthread_rwlock_init() 自动申请的资源） 。
参数：
    rwlock：读写锁指针。
返回值：
    成功：0
    失败：非 0 错误码
```

### pthread_rwlock_rdlock函数——上读锁

```c
#include <pthread.h>
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
功能：
    以阻塞方式在读写锁上获取读锁（读锁定）。
    如果没有写者持有该锁，并且没有写者阻塞在该锁上，则调用线程会获取读锁。
    如果调用线程未获取读锁，则它将阻塞直到它获取了该锁。一个线程可以在一个读写锁上多次执行读锁定。
    线程可以成功调用 pthread_rwlock_rdlock() 函数 n 次，但是之后该线程必须调用 pthread_rwlock_unlock() 函数 n 次才能解除锁定。
参数：
    rwlock：读写锁指针。
返回值：
    成功：0
    失败：非 0 错误码

int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
    用于尝试以非阻塞的方式来在读写锁上获取读锁。
	如果有任何的写者持有该锁或有写者阻塞在该读写锁上，则立即失败返回。
```

### pthread_rwlock_wrlock函数——上写锁

```c
#include <pthread.h>
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
功能：
    在读写锁上获取写锁（写锁定）。
    如果没有写者持有该锁，并且没有写者读者持有该锁，则调用线程会获取写锁。
    如果调用线程未获取写锁，则它将阻塞直到它获取了该锁。
参数：
    rwlock：读写锁指针。
返回值：
    成功：0
    失败：非 0 错误码

int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
	用于尝试以非阻塞的方式来在读写锁上获取写锁。
	如果有任何的读者或写者持有该锁，则立即失败返回。
```

### pthread_rwlock_unlock函数

```c
#include <pthread.h>
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
功能：
    无论是读锁或写锁，都可以通过此函数解锁。
参数：
    rwlock：读写锁指针。
返回值：
    成功：0
    失败：非 0 错误码
```

### 程序示例_读写硕：

此示例程序中，共创建了 4 个线程，其中两个线程用来写入数据，两个线程用来读取数据。当某个线程读操作时，其他线程允许读操作，却不允许写操作；当某个线程写操作时，其它线程都不允许读或写操作。

```c
pthread_rwlock_t rwlock; //读写锁
int num = 1;

//读操作，其他线程允许读操作，却不允许写操作
void *fun1(void *arg){
    while (1){
        pthread_rwlock_rdlock(&rwlock);
        printf("read num first===%d\n", num);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}

//读操作，其他线程允许读操作，却不允许写操作
void *fun2(void *arg){
    while (1){
        pthread_rwlock_rdlock(&rwlock);
        printf("read num second===%d\n", num);
        pthread_rwlock_unlock(&rwlock);
        sleep(2);
    }
}

//写操作，其它线程都不允许读或写操作
void *fun3(void *arg){
    while (1){
        pthread_rwlock_wrlock(&rwlock);
        num++;
        printf("write thread first\n");
        pthread_rwlock_unlock(&rwlock);
        sleep(2);
    }
}

//写操作，其它线程都不允许读或写操作
void *fun4(void *arg){
    while (1){
        pthread_rwlock_wrlock(&rwlock);
        num++;
        printf("write thread second\n");
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}

int main(){
    pthread_rwlock_init(&rwlock, NULL);//初始化一个读写锁

    //创建线程
    pthread_t ptd1, ptd2, ptd3, ptd4;
    pthread_create(&ptd1, NULL, fun1, NULL);
    pthread_create(&ptd2, NULL, fun2, NULL);
    pthread_create(&ptd3, NULL, fun3, NULL);
    pthread_create(&ptd4, NULL, fun4, NULL);

    //等待线程结束，回收其资源
    pthread_join(ptd1, NULL);
    pthread_join(ptd2, NULL);
    pthread_join(ptd3, NULL);
    pthread_join(ptd4, NULL);

    pthread_rwlock_destroy(&rwlock);//销毁读写锁
    return 0;
}
```

## 条件变量

与互斥锁不同，条件变量是用来等待而不是用来上锁的，**条件变量本身不是锁**！

**条件变量用来自动阻塞一个线程，直到某特殊情况发生为止。通常条件变量和互斥锁同时使用。**

条件变量的两个动作：

- 条件不满, 阻塞线程
- 当条件满足, 通知阻塞的线程开始工作

条件变量的类型: pthread_cond_t。

### pthread_cond_init函数

```c
#include <pthread.h>
int pthread_cond_init(pthread_cond_t *restrict cond,
    const pthread_condattr_t *restrict attr);
功能：
    初始化一个条件变量
参数：
    cond：指向要初始化的条件变量指针。
    attr：条件变量属性，通常为默认值，传NULL即可
        也可以使用静态初始化的方法，初始化条件变量：
        pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
返回值：
    成功：0
    失败：非0错误号
```

### pthread_cond_destroy函数

```c
#include <pthread.h>
int pthread_cond_destroy(pthread_cond_t *cond);
功能：
    销毁一个条件变量
参数：
    cond：指向要初始化的条件变量指针
返回值：
    成功：0
    失败：非0错误号
```

### pthread_cond_wait函数

```c
#include <pthread.h>
int pthread_cond_wait(pthread_cond_t *restrict cond,
    pthread_mutex_t *restrict mutex);
功能：
    阻塞等待一个条件变量
    a) 阻塞等待条件变量cond（参1）满足
    b) 释放已掌握的互斥锁（解锁互斥量）相当于pthread_mutex_unlock(&mutex);
            a) b) 两步为一个原子操作。
    c) 当被唤醒，pthread_cond_wait函数返回时，解除阻塞并重新申请获取互斥锁pthread_mutex_lock(&mutex);
参数：
    cond：指向要初始化的条件变量指针
    mutex：互斥锁

返回值：
    成功：0
    失败：非0错误号

int pthread_cond_timedwait(pthread_cond_t *restrict cond,
    pthread_mutex_t *restrict mutex,
    const struct
                           .*restrict abstime);
功能：
    限时等待一个条件变量
参数：
    cond：指向要初始化的条件变量指针
    mutex：互斥锁
    abstime：绝对时间
返回值：
    成功：0
    失败：非0错误号
```

abstime补充说明：

```c
struct timespec {
    time_t tv_sec;      /* seconds */ // 秒
    long   tv_nsec; /* nanosecondes*/ // 纳秒
}
time_t cur = time(NULL);        //获取当前时间。
struct timespec t;              //定义timespec 结构体变量t
t.tv_sec = cur + 1;             // 定时1秒
pthread_cond_timedwait(&cond, &t);
```

### pthread_cond_signal函数

唤醒至阻塞在条件变量上的线程

```c
#include <pthread.h>
int pthread_cond_signal(pthread_cond_t *cond);
功能：
    唤醒至少一个阻塞在条件变量上的线程
参数：
    cond：指向要初始化的条件变量指针
返回值：
    成功：0
    失败：非0错误号
int pthread_cond_broadcast(pthread_cond_t *cond);
功能：
    唤醒全部阻塞在条件变量上的线程
参数：
    cond：指向要初始化的条件变量指针
返回值：
    成功：0
    失败：非0错误号
```

### 条件变量的优缺点

相较于mutex而言，条件变量可以减少竞争。

如直接使用mutex，除了生产者、消费者之间要竞争互斥量以外，消费者之间也需要竞争互斥量，但如果汇聚（链表）中没有数据，消费者之间竞争互斥锁是无意义的。

有了条件变量机制以后，只有生产者完成生产，才会引起消费者之间的竞争。提高了程序效率

### 程序示例_条件变量：

![条件变量](img\条件变量.png)

## 信号量

信号量广泛用于进程或线程间的同步和互斥，信号量本质上是一个非负的整数计数器，它被用来控制对公共资源的访问。

编程时可根据操作信号量值的结果判断是否对公共资源具有访问的权限，当信号量值大于 0 时，则可以访问，否则将阻塞。

PV 原语是对信号量的操作，一次 P 操作使信号量减１，一次 V 操作使信号量加１。

信号量主要用于进程或线程间的同步和互斥这两种典型情况。

信号量数据类型为：sem_t。

信号量用于互斥：

![信号量互斥操作](img\信号量互斥操作.png)

信号量用于同步：

![信号量同步操作](img\信号量同步操作.png)

### sem_init函数——初始化信号量

```c
#include <semaphore.h>
int sem_init(sem_t *sem, int pshared, unsigned int value);
功能：
    创建一个信号量并初始化它的值。一个无名信号量在被使用前必须先初始化。
参数：
    sem：信号量的地址。
    pshared：等于 0，信号量在线程间共享（常用）；不等于0，信号量在进程间共享。
    value：信号量的初始值。
返回值：
    成功：0
    失败： - 1
```

### sem_destroy函数——销毁信号量

```
#include <semaphore.h>
int sem_destroy(sem_t *sem);
功能：
    删除 sem 标识的信号量。
参数：
    sem：信号量地址。
返回值：
    成功：0
    失败： - 1
```

### 信号量P操作（减1）

```c
#include <semaphore.h>
int sem_wait(sem_t *sem);
功能：
    将信号量的值减 1。操作前，先检查信号量（sem）的值是否为 0，若信号量为 0，此函数会阻塞，直到信号量大于 0 时才进行减 1 操作。
参数：
    sem：信号量的地址。
返回值：
    成功：0
    失败： - 1

int sem_trywait(sem_t *sem);
	以非阻塞的方式来对信号量进行减 1 操作。
	若操作前，信号量的值等于 0，则对信号量的操作失败，函数立即返回。

int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
	限时尝试将信号量的值减 1
	abs_timeout：绝对时间
```

abs_timeout补充说明：

```c
struct timespec {
    time_t tv_sec;      /* seconds */ // 秒
    long   tv_nsec; /* nanosecondes*/ // 纳秒
}
time_t cur = time(NULL);        //获取当前时间。
struct timespec t;              //定义timespec 结构体变量t
t.tv_sec = cur + 1;             // 定时1秒
sem_timedwait(&cond, &t);
```

### 信号量V操作（加1）

```c
#include <semaphore.h>
int sem_post(sem_t *sem);
功能：
    将信号量的值加 1 并发出信号唤醒等待线程（sem_wait()）。
参数：
    sem：信号量的地址。
返回值：
    成功：0
    失败：-1
```

### 获取信号量的值

```c
#include <semaphore.h>
int sem_getvalue(sem_t *sem, int *sval);
功能：
    获取 sem 标识的信号量的值，保存在 sval 中。
参数：
    sem：信号量地址。
    sval：保存信号量值的地址。
返回值：
    成功：0
    失败：-1
```

### 程序示例_信号量：

```c
sem_t sem; //信号量
void printer(char *str){
    sem_wait(&sem);//减一
    while (*str){
        putchar(*str);
        fflush(stdout);
        str++;
        sleep(1);
    }
    printf("\n");
    sem_post(&sem);//加一
}

void *thread_fun1(void *arg){
    char *str1 = "hello";
    printer(str1);
}

void *thread_fun2(void *arg){
    char *str2 = "world";
    printer(str2);
}

int main(void){
    pthread_t tid1, tid2;

    sem_init(&sem, 0, 1); //初始化信号量，初始值为 1

    //创建 2 个线程
    pthread_create(&tid1, NULL, thread_fun1, NULL);
    pthread_create(&tid2, NULL, thread_fun2, NULL);

    //等待线程结束，回收其资源
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    sem_destroy(&sem); //销毁信号量
    return 0;
}
```
