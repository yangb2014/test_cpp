#
# Generic makefile 
#
CROSS		= arm-linux- //交叉编译前缀
SRCDIRS		= ./ 			\   //源代码所在目录
	  	./init	 		    \
		./app/fb  		    \
		./app/font  		\
		./app/color  		\
                ./app/drawpic       \
                ./app/window1       \
                ./app/window2       \
                ./app/window3       \
                ./app/slide_bar     \
                ./app/key_pad       \
                ./app/event         \
                ./app/vector        \
                ./app/devinfo       \
                ./app/gpio          \
                ./app/recal_ts      \
                ./app/down_event    \
                ./app/PQData        \
                ./app/spi           \
                ./app/FTP           \
                ./app/pqd_gen       \
                ./app/linuxserver   \
                ./app/pqd_write     \


//各种flag
ASFLAGS		=
CFLAGS		= -g -Wall 
CXXFLAGS	=
LDFLAGS		=
ARFLAGS		=
OCFLAGS		= 
ODFLAGS		=

INCDIRS		= -I ./include  //自定义头文件所在目录
LIBDIRS		= -L ./lib      //自定义库文件所在目录
LIBS 		= -lts -lpthread -lm -lz //工程所用的库

#
# You shouldn't need to change anything below this point.
#
AS			= $(CROSS)as
CC			= $(CROSS)gcc
CXX			= $(CROSS)g++
LD			= $(CROSS)gcc
AR			= $(CROSS)ar
OC			= $(CROSS)objcopy
OD			= $(CROSS)objdump
RM			= -rm -fr

NAME		:= $(notdir $(CURDIR))  //工程名字
SFILES		:= $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.s)) //所有.s文件名集合
CFILES		:= $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c)) //所有.c文件名集合
CPPFILES	:= $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp)) //所有.cpp文件名集合
OBJS 		:= $(SFILES:.s=.o) $(CFILES:.c=.o) $(CPPFILES:.cpp=.o) //将所有源文件的后缀改为.o后字符串
DEPS		:= $(OBJS:.o=.d)  //所有源文件后缀改为.d后字符串
VPATH		:= $(SRCDIRS)

.PHONY: all rebuild clean  //虚目标
all:
	@$(MAKE) $(NAME)
rebuild:
	@$(MAKE) clean
	@$(MAKE) $(NAME)
$(NAME):	$(OBJS)
	@echo linking ...
	$(LD) $(LDFLAGS) $(LIBDIRS) $(LIBS) -o $@ $^  //链接所有.o文件,生成可执行文件
%.o:	%.s
	@echo assembling $< ...
	$(AS) $(ASFLAGS) $(INCDIRS) $< -o $@
%.o:	%.c
	@echo compiling $< ...
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@ //编译.c文件，生成.o文件
%.o:	%.cpp	
	@echo compiling $< ...
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $< -o $@
%.d:	%.c
	@$(CC) $(CFLAGS) $(INCDIRS) -MM $^ -o $@.tmp //生成依赖规则临时文件.tmp
	@sed 's,$(basename $(notdir $@)).o[ :]*,$(@:.d=.o) $@ : ,g' $@.tmp > $@
	//将依赖规则临时文件中内容用sed修改
	@$(RM) $@.tmp  //删除临时文件
    	//例如有一个 add.c 文件 包含有add.h头文件文件
        //gcc -MM add.c  会生成 add.o: add.c add.h
        //sed语句将匹配 add.o : 将之改成 add.o add.d : 最终变为add.o add.d : add.c add.h 保存到add.d文件中去
%.d:	%.cpp
	@$(CXX) $(CXXFLAGS) $(INCDIRS) -MM $^ -o $@.tmp
	@sed 's,$(basename $(notdir $@)).o[ :]*,$(@:.d=.o) $@ : ,g' $@.tmp > $@
	@$(RM) $@.tmp
ifeq (mach,mach1)
-include $(DEPS) //引用所有.d文件
endif

clean:
	@$(RM) $(OBJS) $(DEPS) $(NAME) //删除所有非源文件文件
	@echo clean completed
