.class public demo
.super java/lang/Object
.field public static _sc Ljava/util/Scanner;
.field public static global I
.field public static a I
.method public static _ff()I
.limit stack 300
.limit locals 7
getstatic demo/a I
invokestatic demo/_test(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "5^3 is "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc 5
ldc 3
invokestatic demo/_test2(II)I
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "for test\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
ldc 0
istore 0
LOOP_START_0:
iload 0
ldc 712
if_icmplt TRUE_0
bipush 0
goto END_0
TRUE_0:
bipush 1
END_0:
ifeq LOOP_END_0
iload 0
ldc 23
irem
ldc 0
if_icmpeq TRUE_1
bipush 0
goto END_1
TRUE_1:
bipush 1
END_1:
ifne TRUE_2
goto END_2
TRUE_2:
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
END_2:
NEXT_0:
iload 0
ldc 1
iadd
istore 0
goto LOOP_START_0
LOOP_END_0:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "break test\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
ldc 0
istore 0
LOOP_START_1:
iload 0
ldc 10
if_icmplt TRUE_3
bipush 0
goto END_3
TRUE_3:
bipush 1
END_3:
ifeq LOOP_END_1
iload 0
ldc 3
if_icmplt TRUE_4
bipush 0
goto END_4
TRUE_4:
bipush 1
END_4:
ifne TRUE_5
goto END_5
TRUE_5:
goto LOOP_END_1
END_5:
ldc 10
istore 1
LOOP_START_2:
iload 1
iload 0
if_icmplt TRUE_6
bipush 0
goto END_6
TRUE_6:
bipush 1
END_6:
ifne TRUE_7
goto END_7
TRUE_7:
goto LOOP_END_2
END_7:
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc " "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
NEXT_2:
iload 1
ldc 1
isub
istore 1
goto LOOP_START_2
LOOP_END_2:
NEXT_1:
iload 0
ldc 1
iadd
istore 0
goto LOOP_START_1
LOOP_END_1:
ldc 0
ireturn
.end method
.method public static _test(I)V
.limit stack 300
.limit locals 6
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n\"JIZZ\"\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
return
.end method
.method public static _test2(II)I
.limit stack 300
.limit locals 9
ldc 1
istore 2
LOOP_START_3:
iload 1
ldc 0
if_icmpgt TRUE_8
bipush 0
goto END_8
TRUE_8:
bipush 1
END_8:
ifeq LOOP_END_3
iload 1
ldc 2
irem
ldc 1
if_icmpeq TRUE_9
bipush 0
goto END_9
TRUE_9:
bipush 1
END_9:
ifne TRUE_10
goto FALSE_10
TRUE_10:
iload 2
iload 0
imul
istore 2
iload 1
ldc 1
isub
istore 1
goto END_10
FALSE_10:
iload 0
iload 0
imul
istore 0
iload 1
ldc 2
idiv
istore 1
END_10:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "Debug: "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc " "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc " "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 2
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
NEXT_3:
goto LOOP_START_3
LOOP_END_3:
iload 2
ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 10
new java/util/Scanner
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V
putstatic demo/_sc Ljava/util/Scanner;
ldc 10
ldc 5
imul
putstatic demo/global I
ldc 5
putstatic demo/a I
return
.end method
