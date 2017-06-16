.class public demo
.super java/lang/Object
.field public static _sc Ljava/util/Scanner;
.method public static _first()I
.limit stack 0
.limit locals 2
ldc "2.6"
invokestatic java/lang/Double/parseDouble(Ljava/lang/String;)D
ldc "1.6"
invokestatic java/lang/Float/parseFloat(Ljava/lang/String;)F
f2d
dmul

dadd
ldc 0
.end method
