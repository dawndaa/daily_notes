
bomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 3f 00 00 	mov    0x3fd9(%rip),%rax        # 4fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 ca 3e 00 00    	push   0x3eca(%rip)        # 4ef0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 cb 3e 00 00 	bnd jmp *0x3ecb(%rip)        # 4ef8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	push   $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	push   $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	push   $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	push   $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmp 1020 <_init+0x20>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	push   $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmp 1020 <_init+0x20>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	push   $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	push   $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10bf:	90                   	nop
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	68 09 00 00 00       	push   $0x9
    10c9:	f2 e9 51 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10cf:	90                   	nop
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	68 0a 00 00 00       	push   $0xa
    10d9:	f2 e9 41 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10df:	90                   	nop
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	68 0b 00 00 00       	push   $0xb
    10e9:	f2 e9 31 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10ef:	90                   	nop
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	68 0c 00 00 00       	push   $0xc
    10f9:	f2 e9 21 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10ff:	90                   	nop
    1100:	f3 0f 1e fa          	endbr64 
    1104:	68 0d 00 00 00       	push   $0xd
    1109:	f2 e9 11 ff ff ff    	bnd jmp 1020 <_init+0x20>
    110f:	90                   	nop
    1110:	f3 0f 1e fa          	endbr64 
    1114:	68 0e 00 00 00       	push   $0xe
    1119:	f2 e9 01 ff ff ff    	bnd jmp 1020 <_init+0x20>
    111f:	90                   	nop
    1120:	f3 0f 1e fa          	endbr64 
    1124:	68 0f 00 00 00       	push   $0xf
    1129:	f2 e9 f1 fe ff ff    	bnd jmp 1020 <_init+0x20>
    112f:	90                   	nop
    1130:	f3 0f 1e fa          	endbr64 
    1134:	68 10 00 00 00       	push   $0x10
    1139:	f2 e9 e1 fe ff ff    	bnd jmp 1020 <_init+0x20>
    113f:	90                   	nop
    1140:	f3 0f 1e fa          	endbr64 
    1144:	68 11 00 00 00       	push   $0x11
    1149:	f2 e9 d1 fe ff ff    	bnd jmp 1020 <_init+0x20>
    114f:	90                   	nop
    1150:	f3 0f 1e fa          	endbr64 
    1154:	68 12 00 00 00       	push   $0x12
    1159:	f2 e9 c1 fe ff ff    	bnd jmp 1020 <_init+0x20>
    115f:	90                   	nop
    1160:	f3 0f 1e fa          	endbr64 
    1164:	68 13 00 00 00       	push   $0x13
    1169:	f2 e9 b1 fe ff ff    	bnd jmp 1020 <_init+0x20>
    116f:	90                   	nop
    1170:	f3 0f 1e fa          	endbr64 
    1174:	68 14 00 00 00       	push   $0x14
    1179:	f2 e9 a1 fe ff ff    	bnd jmp 1020 <_init+0x20>
    117f:	90                   	nop
    1180:	f3 0f 1e fa          	endbr64 
    1184:	68 15 00 00 00       	push   $0x15
    1189:	f2 e9 91 fe ff ff    	bnd jmp 1020 <_init+0x20>
    118f:	90                   	nop
    1190:	f3 0f 1e fa          	endbr64 
    1194:	68 16 00 00 00       	push   $0x16
    1199:	f2 e9 81 fe ff ff    	bnd jmp 1020 <_init+0x20>
    119f:	90                   	nop
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	68 17 00 00 00       	push   $0x17
    11a9:	f2 e9 71 fe ff ff    	bnd jmp 1020 <_init+0x20>
    11af:	90                   	nop
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	68 18 00 00 00       	push   $0x18
    11b9:	f2 e9 61 fe ff ff    	bnd jmp 1020 <_init+0x20>
    11bf:	90                   	nop
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	68 19 00 00 00       	push   $0x19
    11c9:	f2 e9 51 fe ff ff    	bnd jmp 1020 <_init+0x20>
    11cf:	90                   	nop
    11d0:	f3 0f 1e fa          	endbr64 
    11d4:	68 1a 00 00 00       	push   $0x1a
    11d9:	f2 e9 41 fe ff ff    	bnd jmp 1020 <_init+0x20>
    11df:	90                   	nop

Disassembly of section .plt.got:

00000000000011e0 <__cxa_finalize@plt>:
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	f2 ff 25 0d 3e 00 00 	bnd jmp *0x3e0d(%rip)        # 4ff8 <__cxa_finalize@GLIBC_2.2.5>
    11eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

00000000000011f0 <getenv@plt>:
    11f0:	f3 0f 1e fa          	endbr64 
    11f4:	f2 ff 25 05 3d 00 00 	bnd jmp *0x3d05(%rip)        # 4f00 <getenv@GLIBC_2.2.5>
    11fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001200 <__errno_location@plt>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	f2 ff 25 fd 3c 00 00 	bnd jmp *0x3cfd(%rip)        # 4f08 <__errno_location@GLIBC_2.2.5>
    120b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001210 <strcpy@plt>:
    1210:	f3 0f 1e fa          	endbr64 
    1214:	f2 ff 25 f5 3c 00 00 	bnd jmp *0x3cf5(%rip)        # 4f10 <strcpy@GLIBC_2.2.5>
    121b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001220 <puts@plt>:
    1220:	f3 0f 1e fa          	endbr64 
    1224:	f2 ff 25 ed 3c 00 00 	bnd jmp *0x3ced(%rip)        # 4f18 <puts@GLIBC_2.2.5>
    122b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001230 <write@plt>:
    1230:	f3 0f 1e fa          	endbr64 
    1234:	f2 ff 25 e5 3c 00 00 	bnd jmp *0x3ce5(%rip)        # 4f20 <write@GLIBC_2.2.5>
    123b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001240 <strlen@plt>:
    1240:	f3 0f 1e fa          	endbr64 
    1244:	f2 ff 25 dd 3c 00 00 	bnd jmp *0x3cdd(%rip)        # 4f28 <strlen@GLIBC_2.2.5>
    124b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001250 <__stack_chk_fail@plt>:
    1250:	f3 0f 1e fa          	endbr64 
    1254:	f2 ff 25 d5 3c 00 00 	bnd jmp *0x3cd5(%rip)        # 4f30 <__stack_chk_fail@GLIBC_2.4>
    125b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001260 <alarm@plt>:
    1260:	f3 0f 1e fa          	endbr64 
    1264:	f2 ff 25 cd 3c 00 00 	bnd jmp *0x3ccd(%rip)        # 4f38 <alarm@GLIBC_2.2.5>
    126b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001270 <close@plt>:
    1270:	f3 0f 1e fa          	endbr64 
    1274:	f2 ff 25 c5 3c 00 00 	bnd jmp *0x3cc5(%rip)        # 4f40 <close@GLIBC_2.2.5>
    127b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001280 <read@plt>:
    1280:	f3 0f 1e fa          	endbr64 
    1284:	f2 ff 25 bd 3c 00 00 	bnd jmp *0x3cbd(%rip)        # 4f48 <read@GLIBC_2.2.5>
    128b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001290 <fgets@plt>:
    1290:	f3 0f 1e fa          	endbr64 
    1294:	f2 ff 25 b5 3c 00 00 	bnd jmp *0x3cb5(%rip)        # 4f50 <fgets@GLIBC_2.2.5>
    129b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012a0 <strcmp@plt>:
    12a0:	f3 0f 1e fa          	endbr64 
    12a4:	f2 ff 25 ad 3c 00 00 	bnd jmp *0x3cad(%rip)        # 4f58 <strcmp@GLIBC_2.2.5>
    12ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012b0 <signal@plt>:
    12b0:	f3 0f 1e fa          	endbr64 
    12b4:	f2 ff 25 a5 3c 00 00 	bnd jmp *0x3ca5(%rip)        # 4f60 <signal@GLIBC_2.2.5>
    12bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012c0 <gethostbyname@plt>:
    12c0:	f3 0f 1e fa          	endbr64 
    12c4:	f2 ff 25 9d 3c 00 00 	bnd jmp *0x3c9d(%rip)        # 4f68 <gethostbyname@GLIBC_2.2.5>
    12cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012d0 <__memmove_chk@plt>:
    12d0:	f3 0f 1e fa          	endbr64 
    12d4:	f2 ff 25 95 3c 00 00 	bnd jmp *0x3c95(%rip)        # 4f70 <__memmove_chk@GLIBC_2.3.4>
    12db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012e0 <strtol@plt>:
    12e0:	f3 0f 1e fa          	endbr64 
    12e4:	f2 ff 25 8d 3c 00 00 	bnd jmp *0x3c8d(%rip)        # 4f78 <strtol@GLIBC_2.2.5>
    12eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012f0 <fflush@plt>:
    12f0:	f3 0f 1e fa          	endbr64 
    12f4:	f2 ff 25 85 3c 00 00 	bnd jmp *0x3c85(%rip)        # 4f80 <fflush@GLIBC_2.2.5>
    12fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001300 <__isoc99_sscanf@plt>:
    1300:	f3 0f 1e fa          	endbr64 
    1304:	f2 ff 25 7d 3c 00 00 	bnd jmp *0x3c7d(%rip)        # 4f88 <__isoc99_sscanf@GLIBC_2.7>
    130b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001310 <__printf_chk@plt>:
    1310:	f3 0f 1e fa          	endbr64 
    1314:	f2 ff 25 75 3c 00 00 	bnd jmp *0x3c75(%rip)        # 4f90 <__printf_chk@GLIBC_2.3.4>
    131b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001320 <fopen@plt>:
    1320:	f3 0f 1e fa          	endbr64 
    1324:	f2 ff 25 6d 3c 00 00 	bnd jmp *0x3c6d(%rip)        # 4f98 <fopen@GLIBC_2.2.5>
    132b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001330 <exit@plt>:
    1330:	f3 0f 1e fa          	endbr64 
    1334:	f2 ff 25 65 3c 00 00 	bnd jmp *0x3c65(%rip)        # 4fa0 <exit@GLIBC_2.2.5>
    133b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001340 <connect@plt>:
    1340:	f3 0f 1e fa          	endbr64 
    1344:	f2 ff 25 5d 3c 00 00 	bnd jmp *0x3c5d(%rip)        # 4fa8 <connect@GLIBC_2.2.5>
    134b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001350 <__fprintf_chk@plt>:
    1350:	f3 0f 1e fa          	endbr64 
    1354:	f2 ff 25 55 3c 00 00 	bnd jmp *0x3c55(%rip)        # 4fb0 <__fprintf_chk@GLIBC_2.3.4>
    135b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001360 <sleep@plt>:
    1360:	f3 0f 1e fa          	endbr64 
    1364:	f2 ff 25 4d 3c 00 00 	bnd jmp *0x3c4d(%rip)        # 4fb8 <sleep@GLIBC_2.2.5>
    136b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001370 <__ctype_b_loc@plt>:
    1370:	f3 0f 1e fa          	endbr64 
    1374:	f2 ff 25 45 3c 00 00 	bnd jmp *0x3c45(%rip)        # 4fc0 <__ctype_b_loc@GLIBC_2.3>
    137b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001380 <__sprintf_chk@plt>:
    1380:	f3 0f 1e fa          	endbr64 
    1384:	f2 ff 25 3d 3c 00 00 	bnd jmp *0x3c3d(%rip)        # 4fc8 <__sprintf_chk@GLIBC_2.3.4>
    138b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001390 <socket@plt>:
    1390:	f3 0f 1e fa          	endbr64 
    1394:	f2 ff 25 35 3c 00 00 	bnd jmp *0x3c35(%rip)        # 4fd0 <socket@GLIBC_2.2.5>
    139b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000013a0 <_start>:
    13a0:	f3 0f 1e fa          	endbr64 
    13a4:	31 ed                	xor    %ebp,%ebp
    13a6:	49 89 d1             	mov    %rdx,%r9
    13a9:	5e                   	pop    %rsi
    13aa:	48 89 e2             	mov    %rsp,%rdx
    13ad:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    13b1:	50                   	push   %rax
    13b2:	54                   	push   %rsp
    13b3:	45 31 c0             	xor    %r8d,%r8d
    13b6:	31 c9                	xor    %ecx,%ecx
    13b8:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 1489 <main>
    13bf:	ff 15 13 3c 00 00    	call   *0x3c13(%rip)        # 4fd8 <__libc_start_main@GLIBC_2.34>
    13c5:	f4                   	hlt    
    13c6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    13cd:	00 00 00 

00000000000013d0 <deregister_tm_clones>:
    13d0:	48 8d 3d 89 42 00 00 	lea    0x4289(%rip),%rdi        # 5660 <stdout@GLIBC_2.2.5>
    13d7:	48 8d 05 82 42 00 00 	lea    0x4282(%rip),%rax        # 5660 <stdout@GLIBC_2.2.5>
    13de:	48 39 f8             	cmp    %rdi,%rax
    13e1:	74 15                	je     13f8 <deregister_tm_clones+0x28>
    13e3:	48 8b 05 f6 3b 00 00 	mov    0x3bf6(%rip),%rax        # 4fe0 <_ITM_deregisterTMCloneTable@Base>
    13ea:	48 85 c0             	test   %rax,%rax
    13ed:	74 09                	je     13f8 <deregister_tm_clones+0x28>
    13ef:	ff e0                	jmp    *%rax
    13f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    13f8:	c3                   	ret    
    13f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001400 <register_tm_clones>:
    1400:	48 8d 3d 59 42 00 00 	lea    0x4259(%rip),%rdi        # 5660 <stdout@GLIBC_2.2.5>
    1407:	48 8d 35 52 42 00 00 	lea    0x4252(%rip),%rsi        # 5660 <stdout@GLIBC_2.2.5>
    140e:	48 29 fe             	sub    %rdi,%rsi
    1411:	48 89 f0             	mov    %rsi,%rax
    1414:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1418:	48 c1 f8 03          	sar    $0x3,%rax
    141c:	48 01 c6             	add    %rax,%rsi
    141f:	48 d1 fe             	sar    %rsi
    1422:	74 14                	je     1438 <register_tm_clones+0x38>
    1424:	48 8b 05 c5 3b 00 00 	mov    0x3bc5(%rip),%rax        # 4ff0 <_ITM_registerTMCloneTable@Base>
    142b:	48 85 c0             	test   %rax,%rax
    142e:	74 08                	je     1438 <register_tm_clones+0x38>
    1430:	ff e0                	jmp    *%rax
    1432:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1438:	c3                   	ret    
    1439:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001440 <__do_global_dtors_aux>:
    1440:	f3 0f 1e fa          	endbr64 
    1444:	80 3d 3d 42 00 00 00 	cmpb   $0x0,0x423d(%rip)        # 5688 <completed.0>
    144b:	75 2b                	jne    1478 <__do_global_dtors_aux+0x38>
    144d:	55                   	push   %rbp
    144e:	48 83 3d a2 3b 00 00 	cmpq   $0x0,0x3ba2(%rip)        # 4ff8 <__cxa_finalize@GLIBC_2.2.5>
    1455:	00 
    1456:	48 89 e5             	mov    %rsp,%rbp
    1459:	74 0c                	je     1467 <__do_global_dtors_aux+0x27>
    145b:	48 8b 3d a6 3b 00 00 	mov    0x3ba6(%rip),%rdi        # 5008 <__dso_handle>
    1462:	e8 79 fd ff ff       	call   11e0 <__cxa_finalize@plt>
    1467:	e8 64 ff ff ff       	call   13d0 <deregister_tm_clones>
    146c:	c6 05 15 42 00 00 01 	movb   $0x1,0x4215(%rip)        # 5688 <completed.0>
    1473:	5d                   	pop    %rbp
    1474:	c3                   	ret    
    1475:	0f 1f 00             	nopl   (%rax)
    1478:	c3                   	ret    
    1479:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001480 <frame_dummy>:
    1480:	f3 0f 1e fa          	endbr64 
    1484:	e9 77 ff ff ff       	jmp    1400 <register_tm_clones>

0000000000001489 <main>:
    1489:	f3 0f 1e fa          	endbr64 
    148d:	53                   	push   %rbx
    148e:	83 ff 01             	cmp    $0x1,%edi
    1491:	0f 84 bc 00 00 00    	je     1553 <main+0xca>
    1497:	48 89 f3             	mov    %rsi,%rbx
    149a:	83 ff 02             	cmp    $0x2,%edi
    149d:	0f 85 e5 00 00 00    	jne    1588 <main+0xff>
    14a3:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
    14a7:	48 8d 35 56 1b 00 00 	lea    0x1b56(%rip),%rsi        # 3004 <_IO_stdin_used+0x4>
    14ae:	e8 6d fe ff ff       	call   1320 <fopen@plt>
    14b3:	48 89 05 d6 41 00 00 	mov    %rax,0x41d6(%rip)        # 5690 <infile>
    14ba:	48 85 c0             	test   %rax,%rax
    14bd:	0f 84 a3 00 00 00    	je     1566 <main+0xdd>
    14c3:	e8 cc 06 00 00       	call   1b94 <initialize_bomb>
    14c8:	48 8d 3d 71 1b 00 00 	lea    0x1b71(%rip),%rdi        # 3040 <_IO_stdin_used+0x40>
    14cf:	e8 4c fd ff ff       	call   1220 <puts@plt>
    14d4:	48 8d 3d a5 1b 00 00 	lea    0x1ba5(%rip),%rdi        # 3080 <_IO_stdin_used+0x80>
    14db:	e8 40 fd ff ff       	call   1220 <puts@plt>
    14e0:	e8 00 08 00 00       	call   1ce5 <read_line>
    14e5:	48 89 c7             	mov    %rax,%rdi
    14e8:	e8 be 00 00 00       	call   15ab <phase_1>
    14ed:	e8 47 09 00 00       	call   1e39 <phase_defused>
    14f2:	e8 ee 07 00 00       	call   1ce5 <read_line>
    14f7:	48 89 c7             	mov    %rax,%rdi
    14fa:	e8 d0 00 00 00       	call   15cf <phase_2>
    14ff:	e8 35 09 00 00       	call   1e39 <phase_defused>
    1504:	e8 dc 07 00 00       	call   1ce5 <read_line>
    1509:	48 89 c7             	mov    %rax,%rdi
    150c:	e8 32 01 00 00       	call   1643 <phase_3>
    1511:	e8 23 09 00 00       	call   1e39 <phase_defused>
    1516:	e8 ca 07 00 00       	call   1ce5 <read_line>
    151b:	48 89 c7             	mov    %rax,%rdi
    151e:	e8 d7 02 00 00       	call   17fa <phase_4>
    1523:	e8 11 09 00 00       	call   1e39 <phase_defused>
    1528:	e8 b8 07 00 00       	call   1ce5 <read_line>
    152d:	48 89 c7             	mov    %rax,%rdi
    1530:	e8 3e 03 00 00       	call   1873 <phase_5>
    1535:	e8 ff 08 00 00       	call   1e39 <phase_defused>
    153a:	e8 a6 07 00 00       	call   1ce5 <read_line>
    153f:	48 89 c7             	mov    %rax,%rdi
    1542:	e8 78 03 00 00       	call   18bf <phase_6>
    1547:	e8 ed 08 00 00       	call   1e39 <phase_defused>
    154c:	b8 00 00 00 00       	mov    $0x0,%eax
    1551:	5b                   	pop    %rbx
    1552:	c3                   	ret    
    1553:	48 8b 05 16 41 00 00 	mov    0x4116(%rip),%rax        # 5670 <stdin@GLIBC_2.2.5>
    155a:	48 89 05 2f 41 00 00 	mov    %rax,0x412f(%rip)        # 5690 <infile>
    1561:	e9 5d ff ff ff       	jmp    14c3 <main+0x3a>
    1566:	48 8b 4b 08          	mov    0x8(%rbx),%rcx
    156a:	48 8b 13             	mov    (%rbx),%rdx
    156d:	48 8d 35 92 1a 00 00 	lea    0x1a92(%rip),%rsi        # 3006 <_IO_stdin_used+0x6>
    1574:	bf 01 00 00 00       	mov    $0x1,%edi
    1579:	e8 92 fd ff ff       	call   1310 <__printf_chk@plt>
    157e:	bf 08 00 00 00       	mov    $0x8,%edi
    1583:	e8 a8 fd ff ff       	call   1330 <exit@plt>
    1588:	48 8b 16             	mov    (%rsi),%rdx
    158b:	48 8d 35 91 1a 00 00 	lea    0x1a91(%rip),%rsi        # 3023 <_IO_stdin_used+0x23>
    1592:	bf 01 00 00 00       	mov    $0x1,%edi
    1597:	b8 00 00 00 00       	mov    $0x0,%eax
    159c:	e8 6f fd ff ff       	call   1310 <__printf_chk@plt>
    15a1:	bf 08 00 00 00       	mov    $0x8,%edi
    15a6:	e8 85 fd ff ff       	call   1330 <exit@plt>

00000000000015ab <phase_1>:
    15ab:	f3 0f 1e fa          	endbr64 
    15af:	48 83 ec 08          	sub    $0x8,%rsp
    15b3:	48 8d 35 f2 1a 00 00 	lea    0x1af2(%rip),%rsi        # 30ac <_IO_stdin_used+0xac>
    15ba:	e8 75 05 00 00       	call   1b34 <strings_not_equal>
    15bf:	85 c0                	test   %eax,%eax
    15c1:	75 05                	jne    15c8 <phase_1+0x1d>
    15c3:	48 83 c4 08          	add    $0x8,%rsp
    15c7:	c3                   	ret    
    15c8:	e8 7b 06 00 00       	call   1c48 <explode_bomb>
    15cd:	eb f4                	jmp    15c3 <phase_1+0x18>

00000000000015cf <phase_2>:
    15cf:	f3 0f 1e fa          	endbr64 
    15d3:	55                   	push   %rbp
    15d4:	53                   	push   %rbx
    15d5:	48 83 ec 28          	sub    $0x28,%rsp
    15d9:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    15e0:	00 00 
    15e2:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    15e7:	31 c0                	xor    %eax,%eax
    15e9:	48 89 e6             	mov    %rsp,%rsi
    15ec:	e8 af 06 00 00       	call   1ca0 <read_six_numbers>
    15f1:	83 3c 24 00          	cmpl   $0x0,(%rsp)
    15f5:	75 07                	jne    15fe <phase_2+0x2f>
    15f7:	83 7c 24 04 01       	cmpl   $0x1,0x4(%rsp)
    15fc:	74 05                	je     1603 <phase_2+0x34>
    15fe:	e8 45 06 00 00       	call   1c48 <explode_bomb>
    1603:	48 89 e3             	mov    %rsp,%rbx
    1606:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
    160b:	eb 09                	jmp    1616 <phase_2+0x47>
    160d:	48 83 c3 04          	add    $0x4,%rbx
    1611:	48 39 eb             	cmp    %rbp,%rbx
    1614:	74 11                	je     1627 <phase_2+0x58>
    1616:	8b 43 04             	mov    0x4(%rbx),%eax
    1619:	03 03                	add    (%rbx),%eax
    161b:	39 43 08             	cmp    %eax,0x8(%rbx)
    161e:	74 ed                	je     160d <phase_2+0x3e>
    1620:	e8 23 06 00 00       	call   1c48 <explode_bomb>
    1625:	eb e6                	jmp    160d <phase_2+0x3e>
    1627:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    162c:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    1633:	00 00 
    1635:	75 07                	jne    163e <phase_2+0x6f>
    1637:	48 83 c4 28          	add    $0x28,%rsp
    163b:	5b                   	pop    %rbx
    163c:	5d                   	pop    %rbp
    163d:	c3                   	ret    
    163e:	e8 0d fc ff ff       	call   1250 <__stack_chk_fail@plt>

0000000000001643 <phase_3>:
    1643:	f3 0f 1e fa          	endbr64 
    1647:	48 83 ec 28          	sub    $0x28,%rsp
    164b:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1652:	00 00 
    1654:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    1659:	31 c0                	xor    %eax,%eax
    165b:	48 8d 4c 24 0f       	lea    0xf(%rsp),%rcx
    1660:	48 8d 54 24 10       	lea    0x10(%rsp),%rdx
    1665:	4c 8d 44 24 14       	lea    0x14(%rsp),%r8
    166a:	48 8d 35 59 1a 00 00 	lea    0x1a59(%rip),%rsi        # 30ca <_IO_stdin_used+0xca>
    1671:	e8 8a fc ff ff       	call   1300 <__isoc99_sscanf@plt>
    1676:	83 f8 02             	cmp    $0x2,%eax
    1679:	7e 20                	jle    169b <phase_3+0x58>
    167b:	83 7c 24 10 07       	cmpl   $0x7,0x10(%rsp)
    1680:	0f 87 0d 01 00 00    	ja     1793 <phase_3+0x150>
    1686:	8b 44 24 10          	mov    0x10(%rsp),%eax
    168a:	48 8d 15 4f 1a 00 00 	lea    0x1a4f(%rip),%rdx        # 30e0 <_IO_stdin_used+0xe0>
    1691:	48 63 04 82          	movslq (%rdx,%rax,4),%rax
    1695:	48 01 d0             	add    %rdx,%rax
    1698:	3e ff e0             	notrack jmp *%rax
    169b:	e8 a8 05 00 00       	call   1c48 <explode_bomb>
    16a0:	eb d9                	jmp    167b <phase_3+0x38>
    16a2:	b8 72 00 00 00       	mov    $0x72,%eax
    16a7:	81 7c 24 14 44 02 00 	cmpl   $0x244,0x14(%rsp)
    16ae:	00 
    16af:	0f 84 e8 00 00 00    	je     179d <phase_3+0x15a>
    16b5:	e8 8e 05 00 00       	call   1c48 <explode_bomb>
    16ba:	b8 72 00 00 00       	mov    $0x72,%eax
    16bf:	e9 d9 00 00 00       	jmp    179d <phase_3+0x15a>
    16c4:	b8 66 00 00 00       	mov    $0x66,%eax
    16c9:	81 7c 24 14 ed 01 00 	cmpl   $0x1ed,0x14(%rsp)
    16d0:	00 
    16d1:	0f 84 c6 00 00 00    	je     179d <phase_3+0x15a>
    16d7:	e8 6c 05 00 00       	call   1c48 <explode_bomb>
    16dc:	b8 66 00 00 00       	mov    $0x66,%eax
    16e1:	e9 b7 00 00 00       	jmp    179d <phase_3+0x15a>
    16e6:	b8 67 00 00 00       	mov    $0x67,%eax
    16eb:	81 7c 24 14 0b 01 00 	cmpl   $0x10b,0x14(%rsp)
    16f2:	00 
    16f3:	0f 84 a4 00 00 00    	je     179d <phase_3+0x15a>
    16f9:	e8 4a 05 00 00       	call   1c48 <explode_bomb>
    16fe:	b8 67 00 00 00       	mov    $0x67,%eax
    1703:	e9 95 00 00 00       	jmp    179d <phase_3+0x15a>
    1708:	b8 7a 00 00 00       	mov    $0x7a,%eax
    170d:	81 7c 24 14 51 01 00 	cmpl   $0x151,0x14(%rsp)
    1714:	00 
    1715:	0f 84 82 00 00 00    	je     179d <phase_3+0x15a>
    171b:	e8 28 05 00 00       	call   1c48 <explode_bomb>
    1720:	b8 7a 00 00 00       	mov    $0x7a,%eax
    1725:	eb 76                	jmp    179d <phase_3+0x15a>
    1727:	b8 71 00 00 00       	mov    $0x71,%eax
    172c:	81 7c 24 14 14 03 00 	cmpl   $0x314,0x14(%rsp)
    1733:	00 
    1734:	74 67                	je     179d <phase_3+0x15a>
    1736:	e8 0d 05 00 00       	call   1c48 <explode_bomb>
    173b:	b8 71 00 00 00       	mov    $0x71,%eax
    1740:	eb 5b                	jmp    179d <phase_3+0x15a>
    1742:	b8 78 00 00 00       	mov    $0x78,%eax
    1747:	81 7c 24 14 cb 01 00 	cmpl   $0x1cb,0x14(%rsp)
    174e:	00 
    174f:	74 4c                	je     179d <phase_3+0x15a>
    1751:	e8 f2 04 00 00       	call   1c48 <explode_bomb>
    1756:	b8 78 00 00 00       	mov    $0x78,%eax
    175b:	eb 40                	jmp    179d <phase_3+0x15a>
    175d:	b8 69 00 00 00       	mov    $0x69,%eax
    1762:	81 7c 24 14 a0 01 00 	cmpl   $0x1a0,0x14(%rsp)
    1769:	00 
    176a:	74 31                	je     179d <phase_3+0x15a>
    176c:	e8 d7 04 00 00       	call   1c48 <explode_bomb>
    1771:	b8 69 00 00 00       	mov    $0x69,%eax
    1776:	eb 25                	jmp    179d <phase_3+0x15a>
    1778:	b8 61 00 00 00       	mov    $0x61,%eax
    177d:	81 7c 24 14 7a 03 00 	cmpl   $0x37a,0x14(%rsp)
    1784:	00 
    1785:	74 16                	je     179d <phase_3+0x15a>
    1787:	e8 bc 04 00 00       	call   1c48 <explode_bomb>
    178c:	b8 61 00 00 00       	mov    $0x61,%eax
    1791:	eb 0a                	jmp    179d <phase_3+0x15a>
    1793:	e8 b0 04 00 00       	call   1c48 <explode_bomb>
    1798:	b8 6f 00 00 00       	mov    $0x6f,%eax
    179d:	38 44 24 0f          	cmp    %al,0xf(%rsp)
    17a1:	75 15                	jne    17b8 <phase_3+0x175>
    17a3:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    17a8:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    17af:	00 00 
    17b1:	75 0c                	jne    17bf <phase_3+0x17c>
    17b3:	48 83 c4 28          	add    $0x28,%rsp
    17b7:	c3                   	ret    
    17b8:	e8 8b 04 00 00       	call   1c48 <explode_bomb>
    17bd:	eb e4                	jmp    17a3 <phase_3+0x160>
    17bf:	e8 8c fa ff ff       	call   1250 <__stack_chk_fail@plt>

00000000000017c4 <func4>:
    17c4:	f3 0f 1e fa          	endbr64 
    17c8:	53                   	push   %rbx
    17c9:	89 d0                	mov    %edx,%eax
    17cb:	29 f0                	sub    %esi,%eax
    17cd:	89 c3                	mov    %eax,%ebx
    17cf:	c1 eb 1f             	shr    $0x1f,%ebx
    17d2:	01 c3                	add    %eax,%ebx
    17d4:	d1 fb                	sar    %ebx
    17d6:	01 f3                	add    %esi,%ebx
    17d8:	39 fb                	cmp    %edi,%ebx
    17da:	7f 06                	jg     17e2 <func4+0x1e>
    17dc:	7c 10                	jl     17ee <func4+0x2a>
    17de:	89 d8                	mov    %ebx,%eax
    17e0:	5b                   	pop    %rbx
    17e1:	c3                   	ret    
    17e2:	8d 53 ff             	lea    -0x1(%rbx),%edx
    17e5:	e8 da ff ff ff       	call   17c4 <func4>
    17ea:	01 c3                	add    %eax,%ebx
    17ec:	eb f0                	jmp    17de <func4+0x1a>
    17ee:	8d 73 01             	lea    0x1(%rbx),%esi
    17f1:	e8 ce ff ff ff       	call   17c4 <func4>
    17f6:	01 c3                	add    %eax,%ebx
    17f8:	eb e4                	jmp    17de <func4+0x1a>

00000000000017fa <phase_4>:
    17fa:	f3 0f 1e fa          	endbr64 
    17fe:	48 83 ec 18          	sub    $0x18,%rsp
    1802:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1809:	00 00 
    180b:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    1810:	31 c0                	xor    %eax,%eax
    1812:	48 8d 4c 24 04       	lea    0x4(%rsp),%rcx
    1817:	48 89 e2             	mov    %rsp,%rdx
    181a:	48 8d 35 17 1b 00 00 	lea    0x1b17(%rip),%rsi        # 3338 <array.0+0x238>
    1821:	e8 da fa ff ff       	call   1300 <__isoc99_sscanf@plt>
    1826:	83 f8 02             	cmp    $0x2,%eax
    1829:	75 06                	jne    1831 <phase_4+0x37>
    182b:	83 3c 24 0e          	cmpl   $0xe,(%rsp)
    182f:	76 05                	jbe    1836 <phase_4+0x3c>
    1831:	e8 12 04 00 00       	call   1c48 <explode_bomb>
    1836:	ba 0e 00 00 00       	mov    $0xe,%edx
    183b:	be 00 00 00 00       	mov    $0x0,%esi
    1840:	8b 3c 24             	mov    (%rsp),%edi
    1843:	e8 7c ff ff ff       	call   17c4 <func4>
    1848:	83 f8 2b             	cmp    $0x2b,%eax
    184b:	75 07                	jne    1854 <phase_4+0x5a>
    184d:	83 7c 24 04 2b       	cmpl   $0x2b,0x4(%rsp)
    1852:	74 05                	je     1859 <phase_4+0x5f>
    1854:	e8 ef 03 00 00       	call   1c48 <explode_bomb>
    1859:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    185e:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    1865:	00 00 
    1867:	75 05                	jne    186e <phase_4+0x74>
    1869:	48 83 c4 18          	add    $0x18,%rsp
    186d:	c3                   	ret    
    186e:	e8 dd f9 ff ff       	call   1250 <__stack_chk_fail@plt>

0000000000001873 <phase_5>:
    1873:	f3 0f 1e fa          	endbr64 
    1877:	53                   	push   %rbx
    1878:	48 89 fb             	mov    %rdi,%rbx
    187b:	e8 93 02 00 00       	call   1b13 <string_length>
    1880:	83 f8 06             	cmp    $0x6,%eax
    1883:	75 2c                	jne    18b1 <phase_5+0x3e>
    1885:	48 89 d8             	mov    %rbx,%rax
    1888:	48 8d 7b 06          	lea    0x6(%rbx),%rdi
    188c:	b9 00 00 00 00       	mov    $0x0,%ecx
    1891:	48 8d 35 68 18 00 00 	lea    0x1868(%rip),%rsi        # 3100 <array.0>
    1898:	0f b6 10             	movzbl (%rax),%edx
    189b:	83 e2 0f             	and    $0xf,%edx
    189e:	03 0c 96             	add    (%rsi,%rdx,4),%ecx
    18a1:	48 83 c0 01          	add    $0x1,%rax
    18a5:	48 39 f8             	cmp    %rdi,%rax
    18a8:	75 ee                	jne    1898 <phase_5+0x25>
    18aa:	83 f9 28             	cmp    $0x28,%ecx
    18ad:	75 09                	jne    18b8 <phase_5+0x45>
    18af:	5b                   	pop    %rbx
    18b0:	c3                   	ret    
    18b1:	e8 92 03 00 00       	call   1c48 <explode_bomb>
    18b6:	eb cd                	jmp    1885 <phase_5+0x12>
    18b8:	e8 8b 03 00 00       	call   1c48 <explode_bomb>
    18bd:	eb f0                	jmp    18af <phase_5+0x3c>

00000000000018bf <phase_6>:
    18bf:	f3 0f 1e fa          	endbr64 
    18c3:	41 56                	push   %r14
    18c5:	41 55                	push   %r13
    18c7:	41 54                	push   %r12
    18c9:	55                   	push   %rbp
    18ca:	53                   	push   %rbx
    18cb:	48 83 ec 60          	sub    $0x60,%rsp
    18cf:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    18d6:	00 00 
    18d8:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
    18dd:	31 c0                	xor    %eax,%eax
    18df:	49 89 e5             	mov    %rsp,%r13
    18e2:	4c 89 ee             	mov    %r13,%rsi
    18e5:	e8 b6 03 00 00       	call   1ca0 <read_six_numbers>
    18ea:	41 be 01 00 00 00    	mov    $0x1,%r14d
    18f0:	49 89 e4             	mov    %rsp,%r12
    18f3:	eb 28                	jmp    191d <phase_6+0x5e>
    18f5:	e8 4e 03 00 00       	call   1c48 <explode_bomb>
    18fa:	eb 30                	jmp    192c <phase_6+0x6d>
    18fc:	48 83 c3 01          	add    $0x1,%rbx
    1900:	83 fb 05             	cmp    $0x5,%ebx
    1903:	7f 10                	jg     1915 <phase_6+0x56>
    1905:	41 8b 04 9c          	mov    (%r12,%rbx,4),%eax
    1909:	39 45 00             	cmp    %eax,0x0(%rbp)
    190c:	75 ee                	jne    18fc <phase_6+0x3d>
    190e:	e8 35 03 00 00       	call   1c48 <explode_bomb>
    1913:	eb e7                	jmp    18fc <phase_6+0x3d>
    1915:	49 83 c6 01          	add    $0x1,%r14
    1919:	49 83 c5 04          	add    $0x4,%r13
    191d:	4c 89 ed             	mov    %r13,%rbp
    1920:	41 8b 45 00          	mov    0x0(%r13),%eax
    1924:	83 e8 01             	sub    $0x1,%eax
    1927:	83 f8 05             	cmp    $0x5,%eax
    192a:	77 c9                	ja     18f5 <phase_6+0x36>
    192c:	41 83 fe 05          	cmp    $0x5,%r14d
    1930:	7f 05                	jg     1937 <phase_6+0x78>
    1932:	4c 89 f3             	mov    %r14,%rbx
    1935:	eb ce                	jmp    1905 <phase_6+0x46>
    1937:	be 00 00 00 00       	mov    $0x0,%esi
    193c:	8b 0c b4             	mov    (%rsp,%rsi,4),%ecx
    193f:	b8 01 00 00 00       	mov    $0x1,%eax
    1944:	48 8d 15 c5 38 00 00 	lea    0x38c5(%rip),%rdx        # 5210 <node1>
    194b:	83 f9 01             	cmp    $0x1,%ecx
    194e:	7e 0b                	jle    195b <phase_6+0x9c>
    1950:	48 8b 52 08          	mov    0x8(%rdx),%rdx
    1954:	83 c0 01             	add    $0x1,%eax
    1957:	39 c8                	cmp    %ecx,%eax
    1959:	75 f5                	jne    1950 <phase_6+0x91>
    195b:	48 89 54 f4 20       	mov    %rdx,0x20(%rsp,%rsi,8)
    1960:	48 83 c6 01          	add    $0x1,%rsi
    1964:	48 83 fe 06          	cmp    $0x6,%rsi
    1968:	75 d2                	jne    193c <phase_6+0x7d>
    196a:	48 8b 5c 24 20       	mov    0x20(%rsp),%rbx
    196f:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    1974:	48 89 43 08          	mov    %rax,0x8(%rbx)
    1978:	48 8b 54 24 30       	mov    0x30(%rsp),%rdx
    197d:	48 89 50 08          	mov    %rdx,0x8(%rax)
    1981:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
    1986:	48 89 42 08          	mov    %rax,0x8(%rdx)
    198a:	48 8b 54 24 40       	mov    0x40(%rsp),%rdx
    198f:	48 89 50 08          	mov    %rdx,0x8(%rax)
    1993:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
    1998:	48 89 42 08          	mov    %rax,0x8(%rdx)
    199c:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
    19a3:	00 
    19a4:	bd 05 00 00 00       	mov    $0x5,%ebp
    19a9:	eb 09                	jmp    19b4 <phase_6+0xf5>
    19ab:	48 8b 5b 08          	mov    0x8(%rbx),%rbx
    19af:	83 ed 01             	sub    $0x1,%ebp
    19b2:	74 11                	je     19c5 <phase_6+0x106>
    19b4:	48 8b 43 08          	mov    0x8(%rbx),%rax
    19b8:	8b 00                	mov    (%rax),%eax
    19ba:	39 03                	cmp    %eax,(%rbx)
    19bc:	7d ed                	jge    19ab <phase_6+0xec>
    19be:	e8 85 02 00 00       	call   1c48 <explode_bomb>
    19c3:	eb e6                	jmp    19ab <phase_6+0xec>
    19c5:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
    19ca:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    19d1:	00 00 
    19d3:	75 0d                	jne    19e2 <phase_6+0x123>
    19d5:	48 83 c4 60          	add    $0x60,%rsp
    19d9:	5b                   	pop    %rbx
    19da:	5d                   	pop    %rbp
    19db:	41 5c                	pop    %r12
    19dd:	41 5d                	pop    %r13
    19df:	41 5e                	pop    %r14
    19e1:	c3                   	ret    
    19e2:	e8 69 f8 ff ff       	call   1250 <__stack_chk_fail@plt>

00000000000019e7 <fun7>:
    19e7:	f3 0f 1e fa          	endbr64 
    19eb:	48 85 ff             	test   %rdi,%rdi
    19ee:	74 32                	je     1a22 <fun7+0x3b>
    19f0:	48 83 ec 08          	sub    $0x8,%rsp
    19f4:	8b 17                	mov    (%rdi),%edx
    19f6:	39 f2                	cmp    %esi,%edx
    19f8:	7f 0c                	jg     1a06 <fun7+0x1f>
    19fa:	b8 00 00 00 00       	mov    $0x0,%eax
    19ff:	75 12                	jne    1a13 <fun7+0x2c>
    1a01:	48 83 c4 08          	add    $0x8,%rsp
    1a05:	c3                   	ret    
    1a06:	48 8b 7f 08          	mov    0x8(%rdi),%rdi
    1a0a:	e8 d8 ff ff ff       	call   19e7 <fun7>
    1a0f:	01 c0                	add    %eax,%eax
    1a11:	eb ee                	jmp    1a01 <fun7+0x1a>
    1a13:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    1a17:	e8 cb ff ff ff       	call   19e7 <fun7>
    1a1c:	8d 44 00 01          	lea    0x1(%rax,%rax,1),%eax
    1a20:	eb df                	jmp    1a01 <fun7+0x1a>
    1a22:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1a27:	c3                   	ret    

0000000000001a28 <secret_phase>:
    1a28:	f3 0f 1e fa          	endbr64 
    1a2c:	53                   	push   %rbx
    1a2d:	e8 b3 02 00 00       	call   1ce5 <read_line>
    1a32:	48 89 c7             	mov    %rax,%rdi
    1a35:	ba 0a 00 00 00       	mov    $0xa,%edx
    1a3a:	be 00 00 00 00       	mov    $0x0,%esi
    1a3f:	e8 9c f8 ff ff       	call   12e0 <strtol@plt>
    1a44:	89 c3                	mov    %eax,%ebx
    1a46:	83 e8 01             	sub    $0x1,%eax
    1a49:	3d e8 03 00 00       	cmp    $0x3e8,%eax
    1a4e:	77 26                	ja     1a76 <secret_phase+0x4e>
    1a50:	89 de                	mov    %ebx,%esi
    1a52:	48 8d 3d d7 36 00 00 	lea    0x36d7(%rip),%rdi        # 5130 <n1>
    1a59:	e8 89 ff ff ff       	call   19e7 <fun7>
    1a5e:	83 f8 02             	cmp    $0x2,%eax
    1a61:	75 1a                	jne    1a7d <secret_phase+0x55>
    1a63:	48 8d 3d d6 16 00 00 	lea    0x16d6(%rip),%rdi        # 3140 <array.0+0x40>
    1a6a:	e8 b1 f7 ff ff       	call   1220 <puts@plt>
    1a6f:	e8 c5 03 00 00       	call   1e39 <phase_defused>
    1a74:	5b                   	pop    %rbx
    1a75:	c3                   	ret    
    1a76:	e8 cd 01 00 00       	call   1c48 <explode_bomb>
    1a7b:	eb d3                	jmp    1a50 <secret_phase+0x28>
    1a7d:	e8 c6 01 00 00       	call   1c48 <explode_bomb>
    1a82:	eb df                	jmp    1a63 <secret_phase+0x3b>

0000000000001a84 <sig_handler>:
    1a84:	f3 0f 1e fa          	endbr64 
    1a88:	50                   	push   %rax
    1a89:	58                   	pop    %rax
    1a8a:	48 83 ec 08          	sub    $0x8,%rsp
    1a8e:	48 8d 3d d3 16 00 00 	lea    0x16d3(%rip),%rdi        # 3168 <array.0+0x68>
    1a95:	e8 86 f7 ff ff       	call   1220 <puts@plt>
    1a9a:	bf 03 00 00 00       	mov    $0x3,%edi
    1a9f:	e8 bc f8 ff ff       	call   1360 <sleep@plt>
    1aa4:	48 8d 35 57 18 00 00 	lea    0x1857(%rip),%rsi        # 3302 <array.0+0x202>
    1aab:	bf 01 00 00 00       	mov    $0x1,%edi
    1ab0:	b8 00 00 00 00       	mov    $0x0,%eax
    1ab5:	e8 56 f8 ff ff       	call   1310 <__printf_chk@plt>
    1aba:	48 8b 3d 9f 3b 00 00 	mov    0x3b9f(%rip),%rdi        # 5660 <stdout@GLIBC_2.2.5>
    1ac1:	e8 2a f8 ff ff       	call   12f0 <fflush@plt>
    1ac6:	bf 01 00 00 00       	mov    $0x1,%edi
    1acb:	e8 90 f8 ff ff       	call   1360 <sleep@plt>
    1ad0:	48 8d 3d 33 18 00 00 	lea    0x1833(%rip),%rdi        # 330a <array.0+0x20a>
    1ad7:	e8 44 f7 ff ff       	call   1220 <puts@plt>
    1adc:	bf 10 00 00 00       	mov    $0x10,%edi
    1ae1:	e8 4a f8 ff ff       	call   1330 <exit@plt>

0000000000001ae6 <invalid_phase>:
    1ae6:	f3 0f 1e fa          	endbr64 
    1aea:	50                   	push   %rax
    1aeb:	58                   	pop    %rax
    1aec:	48 83 ec 08          	sub    $0x8,%rsp
    1af0:	48 89 fa             	mov    %rdi,%rdx
    1af3:	48 8d 35 18 18 00 00 	lea    0x1818(%rip),%rsi        # 3312 <array.0+0x212>
    1afa:	bf 01 00 00 00       	mov    $0x1,%edi
    1aff:	b8 00 00 00 00       	mov    $0x0,%eax
    1b04:	e8 07 f8 ff ff       	call   1310 <__printf_chk@plt>
    1b09:	bf 08 00 00 00       	mov    $0x8,%edi
    1b0e:	e8 1d f8 ff ff       	call   1330 <exit@plt>

0000000000001b13 <string_length>:
    1b13:	f3 0f 1e fa          	endbr64 
    1b17:	80 3f 00             	cmpb   $0x0,(%rdi)
    1b1a:	74 12                	je     1b2e <string_length+0x1b>
    1b1c:	b8 00 00 00 00       	mov    $0x0,%eax
    1b21:	48 83 c7 01          	add    $0x1,%rdi
    1b25:	83 c0 01             	add    $0x1,%eax
    1b28:	80 3f 00             	cmpb   $0x0,(%rdi)
    1b2b:	75 f4                	jne    1b21 <string_length+0xe>
    1b2d:	c3                   	ret    
    1b2e:	b8 00 00 00 00       	mov    $0x0,%eax
    1b33:	c3                   	ret    

0000000000001b34 <strings_not_equal>:
    1b34:	f3 0f 1e fa          	endbr64 
    1b38:	41 54                	push   %r12
    1b3a:	55                   	push   %rbp
    1b3b:	53                   	push   %rbx
    1b3c:	48 89 fb             	mov    %rdi,%rbx
    1b3f:	48 89 f5             	mov    %rsi,%rbp
    1b42:	e8 cc ff ff ff       	call   1b13 <string_length>
    1b47:	41 89 c4             	mov    %eax,%r12d
    1b4a:	48 89 ef             	mov    %rbp,%rdi
    1b4d:	e8 c1 ff ff ff       	call   1b13 <string_length>
    1b52:	89 c2                	mov    %eax,%edx
    1b54:	b8 01 00 00 00       	mov    $0x1,%eax
    1b59:	41 39 d4             	cmp    %edx,%r12d
    1b5c:	75 31                	jne    1b8f <strings_not_equal+0x5b>
    1b5e:	0f b6 13             	movzbl (%rbx),%edx
    1b61:	84 d2                	test   %dl,%dl
    1b63:	74 1e                	je     1b83 <strings_not_equal+0x4f>
    1b65:	b8 00 00 00 00       	mov    $0x0,%eax
    1b6a:	38 54 05 00          	cmp    %dl,0x0(%rbp,%rax,1)
    1b6e:	75 1a                	jne    1b8a <strings_not_equal+0x56>
    1b70:	48 83 c0 01          	add    $0x1,%rax
    1b74:	0f b6 14 03          	movzbl (%rbx,%rax,1),%edx
    1b78:	84 d2                	test   %dl,%dl
    1b7a:	75 ee                	jne    1b6a <strings_not_equal+0x36>
    1b7c:	b8 00 00 00 00       	mov    $0x0,%eax
    1b81:	eb 0c                	jmp    1b8f <strings_not_equal+0x5b>
    1b83:	b8 00 00 00 00       	mov    $0x0,%eax
    1b88:	eb 05                	jmp    1b8f <strings_not_equal+0x5b>
    1b8a:	b8 01 00 00 00       	mov    $0x1,%eax
    1b8f:	5b                   	pop    %rbx
    1b90:	5d                   	pop    %rbp
    1b91:	41 5c                	pop    %r12
    1b93:	c3                   	ret    

0000000000001b94 <initialize_bomb>:
    1b94:	f3 0f 1e fa          	endbr64 
    1b98:	48 83 ec 08          	sub    $0x8,%rsp
    1b9c:	48 8d 35 e1 fe ff ff 	lea    -0x11f(%rip),%rsi        # 1a84 <sig_handler>
    1ba3:	bf 02 00 00 00       	mov    $0x2,%edi
    1ba8:	e8 03 f7 ff ff       	call   12b0 <signal@plt>
    1bad:	48 83 c4 08          	add    $0x8,%rsp
    1bb1:	c3                   	ret    

0000000000001bb2 <initialize_bomb_solve>:
    1bb2:	f3 0f 1e fa          	endbr64 
    1bb6:	c3                   	ret    

0000000000001bb7 <blank_line>:
    1bb7:	f3 0f 1e fa          	endbr64 
    1bbb:	55                   	push   %rbp
    1bbc:	53                   	push   %rbx
    1bbd:	48 83 ec 08          	sub    $0x8,%rsp
    1bc1:	48 89 fd             	mov    %rdi,%rbp
    1bc4:	0f b6 5d 00          	movzbl 0x0(%rbp),%ebx
    1bc8:	84 db                	test   %bl,%bl
    1bca:	74 1e                	je     1bea <blank_line+0x33>
    1bcc:	e8 9f f7 ff ff       	call   1370 <__ctype_b_loc@plt>
    1bd1:	48 83 c5 01          	add    $0x1,%rbp
    1bd5:	48 0f be db          	movsbq %bl,%rbx
    1bd9:	48 8b 00             	mov    (%rax),%rax
    1bdc:	f6 44 58 01 20       	testb  $0x20,0x1(%rax,%rbx,2)
    1be1:	75 e1                	jne    1bc4 <blank_line+0xd>
    1be3:	b8 00 00 00 00       	mov    $0x0,%eax
    1be8:	eb 05                	jmp    1bef <blank_line+0x38>
    1bea:	b8 01 00 00 00       	mov    $0x1,%eax
    1bef:	48 83 c4 08          	add    $0x8,%rsp
    1bf3:	5b                   	pop    %rbx
    1bf4:	5d                   	pop    %rbp
    1bf5:	c3                   	ret    

0000000000001bf6 <skip>:
    1bf6:	f3 0f 1e fa          	endbr64 
    1bfa:	55                   	push   %rbp
    1bfb:	53                   	push   %rbx
    1bfc:	48 83 ec 08          	sub    $0x8,%rsp
    1c00:	48 8d 2d f9 3a 00 00 	lea    0x3af9(%rip),%rbp        # 5700 <input_strings>
    1c07:	48 63 05 e6 3a 00 00 	movslq 0x3ae6(%rip),%rax        # 56f4 <num_input_strings>
    1c0e:	48 8d 3c 80          	lea    (%rax,%rax,4),%rdi
    1c12:	48 c1 e7 04          	shl    $0x4,%rdi
    1c16:	48 01 ef             	add    %rbp,%rdi
    1c19:	48 8b 15 70 3a 00 00 	mov    0x3a70(%rip),%rdx        # 5690 <infile>
    1c20:	be 50 00 00 00       	mov    $0x50,%esi
    1c25:	e8 66 f6 ff ff       	call   1290 <fgets@plt>
    1c2a:	48 89 c3             	mov    %rax,%rbx
    1c2d:	48 85 c0             	test   %rax,%rax
    1c30:	74 0c                	je     1c3e <skip+0x48>
    1c32:	48 89 c7             	mov    %rax,%rdi
    1c35:	e8 7d ff ff ff       	call   1bb7 <blank_line>
    1c3a:	85 c0                	test   %eax,%eax
    1c3c:	75 c9                	jne    1c07 <skip+0x11>
    1c3e:	48 89 d8             	mov    %rbx,%rax
    1c41:	48 83 c4 08          	add    $0x8,%rsp
    1c45:	5b                   	pop    %rbx
    1c46:	5d                   	pop    %rbp
    1c47:	c3                   	ret    

0000000000001c48 <explode_bomb>:
    1c48:	f3 0f 1e fa          	endbr64 
    1c4c:	50                   	push   %rax
    1c4d:	58                   	pop    %rax
    1c4e:	48 83 ec 08          	sub    $0x8,%rsp
    1c52:	48 8d 3d ca 16 00 00 	lea    0x16ca(%rip),%rdi        # 3323 <array.0+0x223>
    1c59:	e8 c2 f5 ff ff       	call   1220 <puts@plt>
    1c5e:	8b 15 90 3a 00 00    	mov    0x3a90(%rip),%edx        # 56f4 <num_input_strings>
    1c64:	48 8d 35 35 15 00 00 	lea    0x1535(%rip),%rsi        # 31a0 <array.0+0xa0>
    1c6b:	bf 01 00 00 00       	mov    $0x1,%edi
    1c70:	b8 00 00 00 00       	mov    $0x0,%eax
    1c75:	e8 96 f6 ff ff       	call   1310 <__printf_chk@plt>
    1c7a:	8b 15 70 3a 00 00    	mov    0x3a70(%rip),%edx        # 56f0 <score>
    1c80:	48 8d 35 41 15 00 00 	lea    0x1541(%rip),%rsi        # 31c8 <array.0+0xc8>
    1c87:	bf 01 00 00 00       	mov    $0x1,%edi
    1c8c:	b8 00 00 00 00       	mov    $0x0,%eax
    1c91:	e8 7a f6 ff ff       	call   1310 <__printf_chk@plt>
    1c96:	bf 08 00 00 00       	mov    $0x8,%edi
    1c9b:	e8 90 f6 ff ff       	call   1330 <exit@plt>

0000000000001ca0 <read_six_numbers>:
    1ca0:	f3 0f 1e fa          	endbr64 
    1ca4:	48 83 ec 08          	sub    $0x8,%rsp
    1ca8:	48 89 f2             	mov    %rsi,%rdx
    1cab:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
    1caf:	48 8d 46 14          	lea    0x14(%rsi),%rax
    1cb3:	50                   	push   %rax
    1cb4:	48 8d 46 10          	lea    0x10(%rsi),%rax
    1cb8:	50                   	push   %rax
    1cb9:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
    1cbd:	4c 8d 46 08          	lea    0x8(%rsi),%r8
    1cc1:	48 8d 35 64 16 00 00 	lea    0x1664(%rip),%rsi        # 332c <array.0+0x22c>
    1cc8:	b8 00 00 00 00       	mov    $0x0,%eax
    1ccd:	e8 2e f6 ff ff       	call   1300 <__isoc99_sscanf@plt>
    1cd2:	48 83 c4 10          	add    $0x10,%rsp
    1cd6:	83 f8 05             	cmp    $0x5,%eax
    1cd9:	7e 05                	jle    1ce0 <read_six_numbers+0x40>
    1cdb:	48 83 c4 08          	add    $0x8,%rsp
    1cdf:	c3                   	ret    
    1ce0:	e8 63 ff ff ff       	call   1c48 <explode_bomb>

0000000000001ce5 <read_line>:
    1ce5:	f3 0f 1e fa          	endbr64 
    1ce9:	55                   	push   %rbp
    1cea:	53                   	push   %rbx
    1ceb:	48 83 ec 08          	sub    $0x8,%rsp
    1cef:	b8 00 00 00 00       	mov    $0x0,%eax
    1cf4:	e8 fd fe ff ff       	call   1bf6 <skip>
    1cf9:	48 85 c0             	test   %rax,%rax
    1cfc:	74 5d                	je     1d5b <read_line+0x76>
    1cfe:	8b 2d f0 39 00 00    	mov    0x39f0(%rip),%ebp        # 56f4 <num_input_strings>
    1d04:	48 63 c5             	movslq %ebp,%rax
    1d07:	48 8d 1c 80          	lea    (%rax,%rax,4),%rbx
    1d0b:	48 c1 e3 04          	shl    $0x4,%rbx
    1d0f:	48 8d 05 ea 39 00 00 	lea    0x39ea(%rip),%rax        # 5700 <input_strings>
    1d16:	48 01 c3             	add    %rax,%rbx
    1d19:	48 89 df             	mov    %rbx,%rdi
    1d1c:	e8 1f f5 ff ff       	call   1240 <strlen@plt>
    1d21:	83 f8 4e             	cmp    $0x4e,%eax
    1d24:	0f 8f c5 00 00 00    	jg     1def <read_line+0x10a>
    1d2a:	83 e8 01             	sub    $0x1,%eax
    1d2d:	48 98                	cltq   
    1d2f:	48 63 d5             	movslq %ebp,%rdx
    1d32:	48 8d 0c 92          	lea    (%rdx,%rdx,4),%rcx
    1d36:	48 c1 e1 04          	shl    $0x4,%rcx
    1d3a:	48 8d 15 bf 39 00 00 	lea    0x39bf(%rip),%rdx        # 5700 <input_strings>
    1d41:	48 01 ca             	add    %rcx,%rdx
    1d44:	c6 04 02 00          	movb   $0x0,(%rdx,%rax,1)
    1d48:	83 c5 01             	add    $0x1,%ebp
    1d4b:	89 2d a3 39 00 00    	mov    %ebp,0x39a3(%rip)        # 56f4 <num_input_strings>
    1d51:	48 89 d8             	mov    %rbx,%rax
    1d54:	48 83 c4 08          	add    $0x8,%rsp
    1d58:	5b                   	pop    %rbx
    1d59:	5d                   	pop    %rbp
    1d5a:	c3                   	ret    
    1d5b:	48 8b 05 0e 39 00 00 	mov    0x390e(%rip),%rax        # 5670 <stdin@GLIBC_2.2.5>
    1d62:	48 39 05 27 39 00 00 	cmp    %rax,0x3927(%rip)        # 5690 <infile>
    1d69:	74 1b                	je     1d86 <read_line+0xa1>
    1d6b:	48 8d 3d ea 15 00 00 	lea    0x15ea(%rip),%rdi        # 335c <array.0+0x25c>
    1d72:	e8 79 f4 ff ff       	call   11f0 <getenv@plt>
    1d77:	48 85 c0             	test   %rax,%rax
    1d7a:	74 3c                	je     1db8 <read_line+0xd3>
    1d7c:	bf 00 00 00 00       	mov    $0x0,%edi
    1d81:	e8 aa f5 ff ff       	call   1330 <exit@plt>
    1d86:	48 8d 3d b1 15 00 00 	lea    0x15b1(%rip),%rdi        # 333e <array.0+0x23e>
    1d8d:	e8 8e f4 ff ff       	call   1220 <puts@plt>
    1d92:	8b 15 58 39 00 00    	mov    0x3958(%rip),%edx        # 56f0 <score>
    1d98:	48 8d 35 59 14 00 00 	lea    0x1459(%rip),%rsi        # 31f8 <array.0+0xf8>
    1d9f:	bf 01 00 00 00       	mov    $0x1,%edi
    1da4:	b8 00 00 00 00       	mov    $0x0,%eax
    1da9:	e8 62 f5 ff ff       	call   1310 <__printf_chk@plt>
    1dae:	bf 08 00 00 00       	mov    $0x8,%edi
    1db3:	e8 78 f5 ff ff       	call   1330 <exit@plt>
    1db8:	48 8b 05 b1 38 00 00 	mov    0x38b1(%rip),%rax        # 5670 <stdin@GLIBC_2.2.5>
    1dbf:	48 89 05 ca 38 00 00 	mov    %rax,0x38ca(%rip)        # 5690 <infile>
    1dc6:	b8 00 00 00 00       	mov    $0x0,%eax
    1dcb:	e8 26 fe ff ff       	call   1bf6 <skip>
    1dd0:	48 85 c0             	test   %rax,%rax
    1dd3:	0f 85 25 ff ff ff    	jne    1cfe <read_line+0x19>
    1dd9:	48 8d 3d 5e 15 00 00 	lea    0x155e(%rip),%rdi        # 333e <array.0+0x23e>
    1de0:	e8 3b f4 ff ff       	call   1220 <puts@plt>
    1de5:	bf 00 00 00 00       	mov    $0x0,%edi
    1dea:	e8 41 f5 ff ff       	call   1330 <exit@plt>
    1def:	48 8d 3d 71 15 00 00 	lea    0x1571(%rip),%rdi        # 3367 <array.0+0x267>
    1df6:	e8 25 f4 ff ff       	call   1220 <puts@plt>
    1dfb:	8b 05 f3 38 00 00    	mov    0x38f3(%rip),%eax        # 56f4 <num_input_strings>
    1e01:	8d 50 01             	lea    0x1(%rax),%edx
    1e04:	89 15 ea 38 00 00    	mov    %edx,0x38ea(%rip)        # 56f4 <num_input_strings>
    1e0a:	48 98                	cltq   
    1e0c:	48 6b c0 50          	imul   $0x50,%rax,%rax
    1e10:	48 8d 15 e9 38 00 00 	lea    0x38e9(%rip),%rdx        # 5700 <input_strings>
    1e17:	48 be 2a 2a 2a 74 72 	movabs $0x636e7572742a2a2a,%rsi
    1e1e:	75 6e 63 
    1e21:	48 bf 61 74 65 64 2a 	movabs $0x2a2a2a64657461,%rdi
    1e28:	2a 2a 00 
    1e2b:	48 89 34 02          	mov    %rsi,(%rdx,%rax,1)
    1e2f:	48 89 7c 02 08       	mov    %rdi,0x8(%rdx,%rax,1)
    1e34:	e8 0f fe ff ff       	call   1c48 <explode_bomb>

0000000000001e39 <phase_defused>:
    1e39:	f3 0f 1e fa          	endbr64 
    1e3d:	48 83 ec 78          	sub    $0x78,%rsp
    1e41:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1e48:	00 00 
    1e4a:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
    1e4f:	31 c0                	xor    %eax,%eax
    1e51:	8b 15 9d 38 00 00    	mov    0x389d(%rip),%edx        # 56f4 <num_input_strings>
    1e57:	83 fa 03             	cmp    $0x3,%edx
    1e5a:	7f 5b                	jg     1eb7 <phase_defused+0x7e>
    1e5c:	83 05 8d 38 00 00 1e 	addl   $0x1e,0x388d(%rip)        # 56f0 <score>
    1e63:	48 8d 35 18 15 00 00 	lea    0x1518(%rip),%rsi        # 3382 <array.0+0x282>
    1e6a:	bf 01 00 00 00       	mov    $0x1,%edi
    1e6f:	b8 00 00 00 00       	mov    $0x0,%eax
    1e74:	e8 97 f4 ff ff       	call   1310 <__printf_chk@plt>
    1e79:	8b 15 71 38 00 00    	mov    0x3871(%rip),%edx        # 56f0 <score>
    1e7f:	48 8d 35 72 13 00 00 	lea    0x1372(%rip),%rsi        # 31f8 <array.0+0xf8>
    1e86:	bf 01 00 00 00       	mov    $0x1,%edi
    1e8b:	b8 00 00 00 00       	mov    $0x0,%eax
    1e90:	e8 7b f4 ff ff       	call   1310 <__printf_chk@plt>
    1e95:	83 3d 58 38 00 00 06 	cmpl   $0x6,0x3858(%rip)        # 56f4 <num_input_strings>
    1e9c:	74 27                	je     1ec5 <phase_defused+0x8c>
    1e9e:	48 8b 44 24 68       	mov    0x68(%rsp),%rax
    1ea3:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    1eaa:	00 00 
    1eac:	0f 85 9e 00 00 00    	jne    1f50 <phase_defused+0x117>
    1eb2:	48 83 c4 78          	add    $0x78,%rsp
    1eb6:	c3                   	ret    
    1eb7:	83 fa 04             	cmp    $0x4,%edx
    1eba:	75 a7                	jne    1e63 <phase_defused+0x2a>
    1ebc:	83 05 2d 38 00 00 0a 	addl   $0xa,0x382d(%rip)        # 56f0 <score>
    1ec3:	eb 9e                	jmp    1e63 <phase_defused+0x2a>
    1ec5:	48 8d 4c 24 0c       	lea    0xc(%rsp),%rcx
    1eca:	48 8d 54 24 08       	lea    0x8(%rsp),%rdx
    1ecf:	4c 8d 44 24 10       	lea    0x10(%rsp),%r8
    1ed4:	48 8d 35 c5 14 00 00 	lea    0x14c5(%rip),%rsi        # 33a0 <array.0+0x2a0>
    1edb:	48 8d 3d 0e 39 00 00 	lea    0x390e(%rip),%rdi        # 57f0 <input_strings+0xf0>
    1ee2:	b8 00 00 00 00       	mov    $0x0,%eax
    1ee7:	e8 14 f4 ff ff       	call   1300 <__isoc99_sscanf@plt>
    1eec:	83 f8 03             	cmp    $0x3,%eax
    1eef:	74 1a                	je     1f0b <phase_defused+0xd2>
    1ef1:	48 8d 3d e0 13 00 00 	lea    0x13e0(%rip),%rdi        # 32d8 <array.0+0x1d8>
    1ef8:	e8 23 f3 ff ff       	call   1220 <puts@plt>
    1efd:	48 8d 3d ac 14 00 00 	lea    0x14ac(%rip),%rdi        # 33b0 <array.0+0x2b0>
    1f04:	e8 17 f3 ff ff       	call   1220 <puts@plt>
    1f09:	eb 93                	jmp    1e9e <phase_defused+0x65>
    1f0b:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
    1f10:	48 8d 35 92 14 00 00 	lea    0x1492(%rip),%rsi        # 33a9 <array.0+0x2a9>
    1f17:	e8 18 fc ff ff       	call   1b34 <strings_not_equal>
    1f1c:	85 c0                	test   %eax,%eax
    1f1e:	75 d1                	jne    1ef1 <phase_defused+0xb8>
    1f20:	48 8d 3d f9 12 00 00 	lea    0x12f9(%rip),%rdi        # 3220 <array.0+0x120>
    1f27:	e8 f4 f2 ff ff       	call   1220 <puts@plt>
    1f2c:	48 8d 3d 15 13 00 00 	lea    0x1315(%rip),%rdi        # 3248 <array.0+0x148>
    1f33:	e8 e8 f2 ff ff       	call   1220 <puts@plt>
    1f38:	b8 00 00 00 00       	mov    $0x0,%eax
    1f3d:	e8 e6 fa ff ff       	call   1a28 <secret_phase>
    1f42:	48 8d 3d 37 13 00 00 	lea    0x1337(%rip),%rdi        # 3280 <array.0+0x180>
    1f49:	e8 d2 f2 ff ff       	call   1220 <puts@plt>
    1f4e:	eb a1                	jmp    1ef1 <phase_defused+0xb8>
    1f50:	e8 fb f2 ff ff       	call   1250 <__stack_chk_fail@plt>

0000000000001f55 <sigalrm_handler>:
    1f55:	f3 0f 1e fa          	endbr64 
    1f59:	50                   	push   %rax
    1f5a:	58                   	pop    %rax
    1f5b:	48 83 ec 08          	sub    $0x8,%rsp
    1f5f:	b9 00 00 00 00       	mov    $0x0,%ecx
    1f64:	48 8d 15 bd 14 00 00 	lea    0x14bd(%rip),%rdx        # 3428 <array.0+0x328>
    1f6b:	be 01 00 00 00       	mov    $0x1,%esi
    1f70:	48 8b 3d 09 37 00 00 	mov    0x3709(%rip),%rdi        # 5680 <stderr@GLIBC_2.2.5>
    1f77:	b8 00 00 00 00       	mov    $0x0,%eax
    1f7c:	e8 cf f3 ff ff       	call   1350 <__fprintf_chk@plt>
    1f81:	bf 01 00 00 00       	mov    $0x1,%edi
    1f86:	e8 a5 f3 ff ff       	call   1330 <exit@plt>

0000000000001f8b <rio_readlineb>:
    1f8b:	41 56                	push   %r14
    1f8d:	41 55                	push   %r13
    1f8f:	41 54                	push   %r12
    1f91:	55                   	push   %rbp
    1f92:	53                   	push   %rbx
    1f93:	49 89 f4             	mov    %rsi,%r12
    1f96:	48 83 fa 01          	cmp    $0x1,%rdx
    1f9a:	0f 86 92 00 00 00    	jbe    2032 <rio_readlineb+0xa7>
    1fa0:	48 89 fb             	mov    %rdi,%rbx
    1fa3:	4c 8d 74 16 ff       	lea    -0x1(%rsi,%rdx,1),%r14
    1fa8:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    1fae:	48 8d 6f 10          	lea    0x10(%rdi),%rbp
    1fb2:	eb 56                	jmp    200a <rio_readlineb+0x7f>
    1fb4:	e8 47 f2 ff ff       	call   1200 <__errno_location@plt>
    1fb9:	83 38 04             	cmpl   $0x4,(%rax)
    1fbc:	75 55                	jne    2013 <rio_readlineb+0x88>
    1fbe:	ba 00 20 00 00       	mov    $0x2000,%edx
    1fc3:	48 89 ee             	mov    %rbp,%rsi
    1fc6:	8b 3b                	mov    (%rbx),%edi
    1fc8:	e8 b3 f2 ff ff       	call   1280 <read@plt>
    1fcd:	89 c2                	mov    %eax,%edx
    1fcf:	89 43 04             	mov    %eax,0x4(%rbx)
    1fd2:	85 c0                	test   %eax,%eax
    1fd4:	78 de                	js     1fb4 <rio_readlineb+0x29>
    1fd6:	85 c0                	test   %eax,%eax
    1fd8:	74 42                	je     201c <rio_readlineb+0x91>
    1fda:	48 89 6b 08          	mov    %rbp,0x8(%rbx)
    1fde:	48 8b 43 08          	mov    0x8(%rbx),%rax
    1fe2:	0f b6 08             	movzbl (%rax),%ecx
    1fe5:	48 83 c0 01          	add    $0x1,%rax
    1fe9:	48 89 43 08          	mov    %rax,0x8(%rbx)
    1fed:	83 ea 01             	sub    $0x1,%edx
    1ff0:	89 53 04             	mov    %edx,0x4(%rbx)
    1ff3:	49 83 c4 01          	add    $0x1,%r12
    1ff7:	41 88 4c 24 ff       	mov    %cl,-0x1(%r12)
    1ffc:	80 f9 0a             	cmp    $0xa,%cl
    1fff:	74 3c                	je     203d <rio_readlineb+0xb2>
    2001:	41 83 c5 01          	add    $0x1,%r13d
    2005:	4d 39 f4             	cmp    %r14,%r12
    2008:	74 30                	je     203a <rio_readlineb+0xaf>
    200a:	8b 53 04             	mov    0x4(%rbx),%edx
    200d:	85 d2                	test   %edx,%edx
    200f:	7e ad                	jle    1fbe <rio_readlineb+0x33>
    2011:	eb cb                	jmp    1fde <rio_readlineb+0x53>
    2013:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    201a:	eb 05                	jmp    2021 <rio_readlineb+0x96>
    201c:	b8 00 00 00 00       	mov    $0x0,%eax
    2021:	85 c0                	test   %eax,%eax
    2023:	75 29                	jne    204e <rio_readlineb+0xc3>
    2025:	b8 00 00 00 00       	mov    $0x0,%eax
    202a:	41 83 fd 01          	cmp    $0x1,%r13d
    202e:	75 0d                	jne    203d <rio_readlineb+0xb2>
    2030:	eb 13                	jmp    2045 <rio_readlineb+0xba>
    2032:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    2038:	eb 03                	jmp    203d <rio_readlineb+0xb2>
    203a:	4d 89 f4             	mov    %r14,%r12
    203d:	41 c6 04 24 00       	movb   $0x0,(%r12)
    2042:	49 63 c5             	movslq %r13d,%rax
    2045:	5b                   	pop    %rbx
    2046:	5d                   	pop    %rbp
    2047:	41 5c                	pop    %r12
    2049:	41 5d                	pop    %r13
    204b:	41 5e                	pop    %r14
    204d:	c3                   	ret    
    204e:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    2055:	eb ee                	jmp    2045 <rio_readlineb+0xba>

0000000000002057 <submitr>:
    2057:	f3 0f 1e fa          	endbr64 
    205b:	41 57                	push   %r15
    205d:	41 56                	push   %r14
    205f:	41 55                	push   %r13
    2061:	41 54                	push   %r12
    2063:	55                   	push   %rbp
    2064:	53                   	push   %rbx
    2065:	4c 8d 9c 24 00 60 ff 	lea    -0xa000(%rsp),%r11
    206c:	ff 
    206d:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    2074:	48 83 0c 24 00       	orq    $0x0,(%rsp)
    2079:	4c 39 dc             	cmp    %r11,%rsp
    207c:	75 ef                	jne    206d <submitr+0x16>
    207e:	48 83 ec 78          	sub    $0x78,%rsp
    2082:	49 89 fd             	mov    %rdi,%r13
    2085:	89 f5                	mov    %esi,%ebp
    2087:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
    208c:	48 89 4c 24 10       	mov    %rcx,0x10(%rsp)
    2091:	4c 89 44 24 20       	mov    %r8,0x20(%rsp)
    2096:	4c 89 4c 24 18       	mov    %r9,0x18(%rsp)
    209b:	48 8b 9c 24 b0 a0 00 	mov    0xa0b0(%rsp),%rbx
    20a2:	00 
    20a3:	4c 8b bc 24 b8 a0 00 	mov    0xa0b8(%rsp),%r15
    20aa:	00 
    20ab:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    20b2:	00 00 
    20b4:	48 89 84 24 68 a0 00 	mov    %rax,0xa068(%rsp)
    20bb:	00 
    20bc:	31 c0                	xor    %eax,%eax
    20be:	c7 44 24 3c 00 00 00 	movl   $0x0,0x3c(%rsp)
    20c5:	00 
    20c6:	ba 00 00 00 00       	mov    $0x0,%edx
    20cb:	be 01 00 00 00       	mov    $0x1,%esi
    20d0:	bf 02 00 00 00       	mov    $0x2,%edi
    20d5:	e8 b6 f2 ff ff       	call   1390 <socket@plt>
    20da:	85 c0                	test   %eax,%eax
    20dc:	0f 88 12 01 00 00    	js     21f4 <submitr+0x19d>
    20e2:	41 89 c4             	mov    %eax,%r12d
    20e5:	4c 89 ef             	mov    %r13,%rdi
    20e8:	e8 d3 f1 ff ff       	call   12c0 <gethostbyname@plt>
    20ed:	48 85 c0             	test   %rax,%rax
    20f0:	0f 84 4e 01 00 00    	je     2244 <submitr+0x1ed>
    20f6:	4c 8d 6c 24 40       	lea    0x40(%rsp),%r13
    20fb:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
    2102:	00 00 
    2104:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
    210b:	00 00 
    210d:	66 c7 44 24 40 02 00 	movw   $0x2,0x40(%rsp)
    2114:	48 63 50 14          	movslq 0x14(%rax),%rdx
    2118:	48 8b 40 18          	mov    0x18(%rax),%rax
    211c:	48 8d 7c 24 44       	lea    0x44(%rsp),%rdi
    2121:	b9 0c 00 00 00       	mov    $0xc,%ecx
    2126:	48 8b 30             	mov    (%rax),%rsi
    2129:	e8 a2 f1 ff ff       	call   12d0 <__memmove_chk@plt>
    212e:	66 c1 c5 08          	rol    $0x8,%bp
    2132:	66 89 6c 24 42       	mov    %bp,0x42(%rsp)
    2137:	ba 10 00 00 00       	mov    $0x10,%edx
    213c:	4c 89 ee             	mov    %r13,%rsi
    213f:	44 89 e7             	mov    %r12d,%edi
    2142:	e8 f9 f1 ff ff       	call   1340 <connect@plt>
    2147:	85 c0                	test   %eax,%eax
    2149:	0f 88 60 01 00 00    	js     22af <submitr+0x258>
    214f:	48 89 df             	mov    %rbx,%rdi
    2152:	e8 e9 f0 ff ff       	call   1240 <strlen@plt>
    2157:	48 89 c5             	mov    %rax,%rbp
    215a:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    215f:	e8 dc f0 ff ff       	call   1240 <strlen@plt>
    2164:	49 89 c6             	mov    %rax,%r14
    2167:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
    216c:	e8 cf f0 ff ff       	call   1240 <strlen@plt>
    2171:	49 89 c5             	mov    %rax,%r13
    2174:	48 8b 7c 24 18       	mov    0x18(%rsp),%rdi
    2179:	e8 c2 f0 ff ff       	call   1240 <strlen@plt>
    217e:	48 89 c2             	mov    %rax,%rdx
    2181:	4b 8d 84 2e 80 00 00 	lea    0x80(%r14,%r13,1),%rax
    2188:	00 
    2189:	48 01 d0             	add    %rdx,%rax
    218c:	48 8d 54 6d 00       	lea    0x0(%rbp,%rbp,2),%rdx
    2191:	48 01 d0             	add    %rdx,%rax
    2194:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
    219a:	0f 87 6c 01 00 00    	ja     230c <submitr+0x2b5>
    21a0:	48 8d 94 24 60 40 00 	lea    0x4060(%rsp),%rdx
    21a7:	00 
    21a8:	b9 00 04 00 00       	mov    $0x400,%ecx
    21ad:	b8 00 00 00 00       	mov    $0x0,%eax
    21b2:	48 89 d7             	mov    %rdx,%rdi
    21b5:	f3 48 ab             	rep stos %rax,%es:(%rdi)
    21b8:	48 89 df             	mov    %rbx,%rdi
    21bb:	e8 80 f0 ff ff       	call   1240 <strlen@plt>
    21c0:	85 c0                	test   %eax,%eax
    21c2:	0f 84 07 05 00 00    	je     26cf <submitr+0x678>
    21c8:	8d 40 ff             	lea    -0x1(%rax),%eax
    21cb:	4c 8d 6c 03 01       	lea    0x1(%rbx,%rax,1),%r13
    21d0:	48 8d ac 24 60 40 00 	lea    0x4060(%rsp),%rbp
    21d7:	00 
    21d8:	48 8d 84 24 60 80 00 	lea    0x8060(%rsp),%rax
    21df:	00 
    21e0:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
    21e5:	49 be d9 ff 00 00 00 	movabs $0x2000000000ffd9,%r14
    21ec:	00 20 00 
    21ef:	e9 a6 01 00 00       	jmp    239a <submitr+0x343>
    21f4:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    21fb:	3a 20 43 
    21fe:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2205:	20 75 6e 
    2208:	49 89 07             	mov    %rax,(%r15)
    220b:	49 89 57 08          	mov    %rdx,0x8(%r15)
    220f:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2216:	74 6f 20 
    2219:	48 ba 63 72 65 61 74 	movabs $0x7320657461657263,%rdx
    2220:	65 20 73 
    2223:	49 89 47 10          	mov    %rax,0x10(%r15)
    2227:	49 89 57 18          	mov    %rdx,0x18(%r15)
    222b:	41 c7 47 20 6f 63 6b 	movl   $0x656b636f,0x20(%r15)
    2232:	65 
    2233:	66 41 c7 47 24 74 00 	movw   $0x74,0x24(%r15)
    223a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    223f:	e9 03 03 00 00       	jmp    2547 <submitr+0x4f0>
    2244:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
    224b:	3a 20 44 
    224e:	48 ba 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rdx
    2255:	20 75 6e 
    2258:	49 89 07             	mov    %rax,(%r15)
    225b:	49 89 57 08          	mov    %rdx,0x8(%r15)
    225f:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2266:	74 6f 20 
    2269:	48 ba 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rdx
    2270:	76 65 20 
    2273:	49 89 47 10          	mov    %rax,0x10(%r15)
    2277:	49 89 57 18          	mov    %rdx,0x18(%r15)
    227b:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
    2282:	72 20 61 
    2285:	49 89 47 20          	mov    %rax,0x20(%r15)
    2289:	41 c7 47 28 64 64 72 	movl   $0x65726464,0x28(%r15)
    2290:	65 
    2291:	66 41 c7 47 2c 73 73 	movw   $0x7373,0x2c(%r15)
    2298:	41 c6 47 2e 00       	movb   $0x0,0x2e(%r15)
    229d:	44 89 e7             	mov    %r12d,%edi
    22a0:	e8 cb ef ff ff       	call   1270 <close@plt>
    22a5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    22aa:	e9 98 02 00 00       	jmp    2547 <submitr+0x4f0>
    22af:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
    22b6:	3a 20 55 
    22b9:	48 ba 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rdx
    22c0:	20 74 6f 
    22c3:	49 89 07             	mov    %rax,(%r15)
    22c6:	49 89 57 08          	mov    %rdx,0x8(%r15)
    22ca:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
    22d1:	65 63 74 
    22d4:	48 ba 20 74 6f 20 74 	movabs $0x20656874206f7420,%rdx
    22db:	68 65 20 
    22de:	49 89 47 10          	mov    %rax,0x10(%r15)
    22e2:	49 89 57 18          	mov    %rdx,0x18(%r15)
    22e6:	41 c7 47 20 73 65 72 	movl   $0x76726573,0x20(%r15)
    22ed:	76 
    22ee:	66 41 c7 47 24 65 72 	movw   $0x7265,0x24(%r15)
    22f5:	41 c6 47 26 00       	movb   $0x0,0x26(%r15)
    22fa:	44 89 e7             	mov    %r12d,%edi
    22fd:	e8 6e ef ff ff       	call   1270 <close@plt>
    2302:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2307:	e9 3b 02 00 00       	jmp    2547 <submitr+0x4f0>
    230c:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
    2313:	3a 20 52 
    2316:	48 ba 65 73 75 6c 74 	movabs $0x747320746c757365,%rdx
    231d:	20 73 74 
    2320:	49 89 07             	mov    %rax,(%r15)
    2323:	49 89 57 08          	mov    %rdx,0x8(%r15)
    2327:	48 b8 72 69 6e 67 20 	movabs $0x6f6f7420676e6972,%rax
    232e:	74 6f 6f 
    2331:	48 ba 20 6c 61 72 67 	movabs $0x202e656772616c20,%rdx
    2338:	65 2e 20 
    233b:	49 89 47 10          	mov    %rax,0x10(%r15)
    233f:	49 89 57 18          	mov    %rdx,0x18(%r15)
    2343:	48 b8 49 6e 63 72 65 	movabs $0x6573616572636e49,%rax
    234a:	61 73 65 
    234d:	48 ba 20 53 55 42 4d 	movabs $0x5254494d42555320,%rdx
    2354:	49 54 52 
    2357:	49 89 47 20          	mov    %rax,0x20(%r15)
    235b:	49 89 57 28          	mov    %rdx,0x28(%r15)
    235f:	48 b8 5f 4d 41 58 42 	movabs $0x46554258414d5f,%rax
    2366:	55 46 00 
    2369:	49 89 47 30          	mov    %rax,0x30(%r15)
    236d:	44 89 e7             	mov    %r12d,%edi
    2370:	e8 fb ee ff ff       	call   1270 <close@plt>
    2375:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    237a:	e9 c8 01 00 00       	jmp    2547 <submitr+0x4f0>
    237f:	49 0f a3 c6          	bt     %rax,%r14
    2383:	73 21                	jae    23a6 <submitr+0x34f>
    2385:	44 88 45 00          	mov    %r8b,0x0(%rbp)
    2389:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
    238d:	48 83 c3 01          	add    $0x1,%rbx
    2391:	4c 39 eb             	cmp    %r13,%rbx
    2394:	0f 84 35 03 00 00    	je     26cf <submitr+0x678>
    239a:	44 0f b6 03          	movzbl (%rbx),%r8d
    239e:	41 8d 40 d6          	lea    -0x2a(%r8),%eax
    23a2:	3c 35                	cmp    $0x35,%al
    23a4:	76 d9                	jbe    237f <submitr+0x328>
    23a6:	44 89 c0             	mov    %r8d,%eax
    23a9:	83 e0 df             	and    $0xffffffdf,%eax
    23ac:	83 e8 41             	sub    $0x41,%eax
    23af:	3c 19                	cmp    $0x19,%al
    23b1:	76 d2                	jbe    2385 <submitr+0x32e>
    23b3:	41 80 f8 20          	cmp    $0x20,%r8b
    23b7:	74 60                	je     2419 <submitr+0x3c2>
    23b9:	41 8d 40 e0          	lea    -0x20(%r8),%eax
    23bd:	3c 5f                	cmp    $0x5f,%al
    23bf:	76 0a                	jbe    23cb <submitr+0x374>
    23c1:	41 80 f8 09          	cmp    $0x9,%r8b
    23c5:	0f 85 77 02 00 00    	jne    2642 <submitr+0x5eb>
    23cb:	45 0f b6 c0          	movzbl %r8b,%r8d
    23cf:	48 8d 0d 28 11 00 00 	lea    0x1128(%rip),%rcx        # 34fe <array.0+0x3fe>
    23d6:	ba 08 00 00 00       	mov    $0x8,%edx
    23db:	be 01 00 00 00       	mov    $0x1,%esi
    23e0:	48 8b 7c 24 28       	mov    0x28(%rsp),%rdi
    23e5:	b8 00 00 00 00       	mov    $0x0,%eax
    23ea:	e8 91 ef ff ff       	call   1380 <__sprintf_chk@plt>
    23ef:	0f b6 84 24 60 80 00 	movzbl 0x8060(%rsp),%eax
    23f6:	00 
    23f7:	88 45 00             	mov    %al,0x0(%rbp)
    23fa:	0f b6 84 24 61 80 00 	movzbl 0x8061(%rsp),%eax
    2401:	00 
    2402:	88 45 01             	mov    %al,0x1(%rbp)
    2405:	0f b6 84 24 62 80 00 	movzbl 0x8062(%rsp),%eax
    240c:	00 
    240d:	88 45 02             	mov    %al,0x2(%rbp)
    2410:	48 8d 6d 03          	lea    0x3(%rbp),%rbp
    2414:	e9 74 ff ff ff       	jmp    238d <submitr+0x336>
    2419:	c6 45 00 2b          	movb   $0x2b,0x0(%rbp)
    241d:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
    2421:	e9 67 ff ff ff       	jmp    238d <submitr+0x336>
    2426:	48 01 c5             	add    %rax,%rbp
    2429:	48 29 c3             	sub    %rax,%rbx
    242c:	0f 84 08 03 00 00    	je     273a <submitr+0x6e3>
    2432:	48 89 da             	mov    %rbx,%rdx
    2435:	48 89 ee             	mov    %rbp,%rsi
    2438:	44 89 e7             	mov    %r12d,%edi
    243b:	e8 f0 ed ff ff       	call   1230 <write@plt>
    2440:	48 85 c0             	test   %rax,%rax
    2443:	7f e1                	jg     2426 <submitr+0x3cf>
    2445:	e8 b6 ed ff ff       	call   1200 <__errno_location@plt>
    244a:	83 38 04             	cmpl   $0x4,(%rax)
    244d:	0f 85 90 01 00 00    	jne    25e3 <submitr+0x58c>
    2453:	4c 89 e8             	mov    %r13,%rax
    2456:	eb ce                	jmp    2426 <submitr+0x3cf>
    2458:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    245f:	3a 20 43 
    2462:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2469:	20 75 6e 
    246c:	49 89 07             	mov    %rax,(%r15)
    246f:	49 89 57 08          	mov    %rdx,0x8(%r15)
    2473:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    247a:	74 6f 20 
    247d:	48 ba 72 65 61 64 20 	movabs $0x7269662064616572,%rdx
    2484:	66 69 72 
    2487:	49 89 47 10          	mov    %rax,0x10(%r15)
    248b:	49 89 57 18          	mov    %rdx,0x18(%r15)
    248f:	48 b8 73 74 20 68 65 	movabs $0x6564616568207473,%rax
    2496:	61 64 65 
    2499:	48 ba 72 20 66 72 6f 	movabs $0x73206d6f72662072,%rdx
    24a0:	6d 20 73 
    24a3:	49 89 47 20          	mov    %rax,0x20(%r15)
    24a7:	49 89 57 28          	mov    %rdx,0x28(%r15)
    24ab:	41 c7 47 30 65 72 76 	movl   $0x65767265,0x30(%r15)
    24b2:	65 
    24b3:	66 41 c7 47 34 72 00 	movw   $0x72,0x34(%r15)
    24ba:	44 89 e7             	mov    %r12d,%edi
    24bd:	e8 ae ed ff ff       	call   1270 <close@plt>
    24c2:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    24c7:	eb 7e                	jmp    2547 <submitr+0x4f0>
    24c9:	4c 8d 8c 24 60 80 00 	lea    0x8060(%rsp),%r9
    24d0:	00 
    24d1:	48 8d 0d 78 0f 00 00 	lea    0xf78(%rip),%rcx        # 3450 <array.0+0x350>
    24d8:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    24df:	be 01 00 00 00       	mov    $0x1,%esi
    24e4:	4c 89 ff             	mov    %r15,%rdi
    24e7:	b8 00 00 00 00       	mov    $0x0,%eax
    24ec:	e8 8f ee ff ff       	call   1380 <__sprintf_chk@plt>
    24f1:	44 89 e7             	mov    %r12d,%edi
    24f4:	e8 77 ed ff ff       	call   1270 <close@plt>
    24f9:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    24fe:	eb 47                	jmp    2547 <submitr+0x4f0>
    2500:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    2507:	00 
    2508:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    250d:	ba 00 20 00 00       	mov    $0x2000,%edx
    2512:	e8 74 fa ff ff       	call   1f8b <rio_readlineb>
    2517:	48 85 c0             	test   %rax,%rax
    251a:	7e 54                	jle    2570 <submitr+0x519>
    251c:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    2523:	00 
    2524:	4c 89 ff             	mov    %r15,%rdi
    2527:	e8 e4 ec ff ff       	call   1210 <strcpy@plt>
    252c:	44 89 e7             	mov    %r12d,%edi
    252f:	e8 3c ed ff ff       	call   1270 <close@plt>
    2534:	48 8d 35 de 0f 00 00 	lea    0xfde(%rip),%rsi        # 3519 <array.0+0x419>
    253b:	4c 89 ff             	mov    %r15,%rdi
    253e:	e8 5d ed ff ff       	call   12a0 <strcmp@plt>
    2543:	f7 d8                	neg    %eax
    2545:	19 c0                	sbb    %eax,%eax
    2547:	48 8b 94 24 68 a0 00 	mov    0xa068(%rsp),%rdx
    254e:	00 
    254f:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    2556:	00 00 
    2558:	0f 85 f8 02 00 00    	jne    2856 <submitr+0x7ff>
    255e:	48 81 c4 78 a0 00 00 	add    $0xa078,%rsp
    2565:	5b                   	pop    %rbx
    2566:	5d                   	pop    %rbp
    2567:	41 5c                	pop    %r12
    2569:	41 5d                	pop    %r13
    256b:	41 5e                	pop    %r14
    256d:	41 5f                	pop    %r15
    256f:	c3                   	ret    
    2570:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    2577:	3a 20 43 
    257a:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2581:	20 75 6e 
    2584:	49 89 07             	mov    %rax,(%r15)
    2587:	49 89 57 08          	mov    %rdx,0x8(%r15)
    258b:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2592:	74 6f 20 
    2595:	48 ba 72 65 61 64 20 	movabs $0x6174732064616572,%rdx
    259c:	73 74 61 
    259f:	49 89 47 10          	mov    %rax,0x10(%r15)
    25a3:	49 89 57 18          	mov    %rdx,0x18(%r15)
    25a7:	48 b8 74 75 73 20 6d 	movabs $0x7373656d20737574,%rax
    25ae:	65 73 73 
    25b1:	48 ba 61 67 65 20 66 	movabs $0x6d6f726620656761,%rdx
    25b8:	72 6f 6d 
    25bb:	49 89 47 20          	mov    %rax,0x20(%r15)
    25bf:	49 89 57 28          	mov    %rdx,0x28(%r15)
    25c3:	48 b8 20 73 65 72 76 	movabs $0x72657672657320,%rax
    25ca:	65 72 00 
    25cd:	49 89 47 30          	mov    %rax,0x30(%r15)
    25d1:	44 89 e7             	mov    %r12d,%edi
    25d4:	e8 97 ec ff ff       	call   1270 <close@plt>
    25d9:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    25de:	e9 64 ff ff ff       	jmp    2547 <submitr+0x4f0>
    25e3:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    25ea:	3a 20 43 
    25ed:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    25f4:	20 75 6e 
    25f7:	49 89 07             	mov    %rax,(%r15)
    25fa:	49 89 57 08          	mov    %rdx,0x8(%r15)
    25fe:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2605:	74 6f 20 
    2608:	48 ba 77 72 69 74 65 	movabs $0x6f74206574697277,%rdx
    260f:	20 74 6f 
    2612:	49 89 47 10          	mov    %rax,0x10(%r15)
    2616:	49 89 57 18          	mov    %rdx,0x18(%r15)
    261a:	48 b8 20 74 68 65 20 	movabs $0x7265732065687420,%rax
    2621:	73 65 72 
    2624:	49 89 47 20          	mov    %rax,0x20(%r15)
    2628:	41 c7 47 28 76 65 72 	movl   $0x726576,0x28(%r15)
    262f:	00 
    2630:	44 89 e7             	mov    %r12d,%edi
    2633:	e8 38 ec ff ff       	call   1270 <close@plt>
    2638:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    263d:	e9 05 ff ff ff       	jmp    2547 <submitr+0x4f0>
    2642:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
    2649:	3a 20 52 
    264c:	48 ba 65 73 75 6c 74 	movabs $0x747320746c757365,%rdx
    2653:	20 73 74 
    2656:	49 89 07             	mov    %rax,(%r15)
    2659:	49 89 57 08          	mov    %rdx,0x8(%r15)
    265d:	48 b8 72 69 6e 67 20 	movabs $0x6e6f6320676e6972,%rax
    2664:	63 6f 6e 
    2667:	48 ba 74 61 69 6e 73 	movabs $0x6e6120736e696174,%rdx
    266e:	20 61 6e 
    2671:	49 89 47 10          	mov    %rax,0x10(%r15)
    2675:	49 89 57 18          	mov    %rdx,0x18(%r15)
    2679:	48 b8 20 69 6c 6c 65 	movabs $0x6c6167656c6c6920,%rax
    2680:	67 61 6c 
    2683:	48 ba 20 6f 72 20 75 	movabs $0x72706e7520726f20,%rdx
    268a:	6e 70 72 
    268d:	49 89 47 20          	mov    %rax,0x20(%r15)
    2691:	49 89 57 28          	mov    %rdx,0x28(%r15)
    2695:	48 b8 69 6e 74 61 62 	movabs $0x20656c6261746e69,%rax
    269c:	6c 65 20 
    269f:	48 ba 63 68 61 72 61 	movabs $0x6574636172616863,%rdx
    26a6:	63 74 65 
    26a9:	49 89 47 30          	mov    %rax,0x30(%r15)
    26ad:	49 89 57 38          	mov    %rdx,0x38(%r15)
    26b1:	66 41 c7 47 40 72 2e 	movw   $0x2e72,0x40(%r15)
    26b8:	41 c6 47 42 00       	movb   $0x0,0x42(%r15)
    26bd:	44 89 e7             	mov    %r12d,%edi
    26c0:	e8 ab eb ff ff       	call   1270 <close@plt>
    26c5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    26ca:	e9 78 fe ff ff       	jmp    2547 <submitr+0x4f0>
    26cf:	48 8d 9c 24 60 20 00 	lea    0x2060(%rsp),%rbx
    26d6:	00 
    26d7:	48 83 ec 08          	sub    $0x8,%rsp
    26db:	48 8d 84 24 68 40 00 	lea    0x4068(%rsp),%rax
    26e2:	00 
    26e3:	50                   	push   %rax
    26e4:	ff 74 24 28          	push   0x28(%rsp)
    26e8:	ff 74 24 38          	push   0x38(%rsp)
    26ec:	4c 8b 4c 24 30       	mov    0x30(%rsp),%r9
    26f1:	4c 8b 44 24 28       	mov    0x28(%rsp),%r8
    26f6:	48 8d 0d 83 0d 00 00 	lea    0xd83(%rip),%rcx        # 3480 <array.0+0x380>
    26fd:	ba 00 20 00 00       	mov    $0x2000,%edx
    2702:	be 01 00 00 00       	mov    $0x1,%esi
    2707:	48 89 df             	mov    %rbx,%rdi
    270a:	b8 00 00 00 00       	mov    $0x0,%eax
    270f:	e8 6c ec ff ff       	call   1380 <__sprintf_chk@plt>
    2714:	48 83 c4 20          	add    $0x20,%rsp
    2718:	48 89 df             	mov    %rbx,%rdi
    271b:	e8 20 eb ff ff       	call   1240 <strlen@plt>
    2720:	48 89 c3             	mov    %rax,%rbx
    2723:	48 8d ac 24 60 20 00 	lea    0x2060(%rsp),%rbp
    272a:	00 
    272b:	41 bd 00 00 00 00    	mov    $0x0,%r13d
    2731:	48 85 c0             	test   %rax,%rax
    2734:	0f 85 f8 fc ff ff    	jne    2432 <submitr+0x3db>
    273a:	44 89 64 24 50       	mov    %r12d,0x50(%rsp)
    273f:	c7 44 24 54 00 00 00 	movl   $0x0,0x54(%rsp)
    2746:	00 
    2747:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    274c:	48 8d 44 24 60       	lea    0x60(%rsp),%rax
    2751:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
    2756:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    275d:	00 
    275e:	ba 00 20 00 00       	mov    $0x2000,%edx
    2763:	e8 23 f8 ff ff       	call   1f8b <rio_readlineb>
    2768:	48 85 c0             	test   %rax,%rax
    276b:	0f 8e e7 fc ff ff    	jle    2458 <submitr+0x401>
    2771:	48 8d 4c 24 3c       	lea    0x3c(%rsp),%rcx
    2776:	48 8d 94 24 60 60 00 	lea    0x6060(%rsp),%rdx
    277d:	00 
    277e:	48 8d bc 24 60 20 00 	lea    0x2060(%rsp),%rdi
    2785:	00 
    2786:	4c 8d 84 24 60 80 00 	lea    0x8060(%rsp),%r8
    278d:	00 
    278e:	48 8d 35 70 0d 00 00 	lea    0xd70(%rip),%rsi        # 3505 <array.0+0x405>
    2795:	b8 00 00 00 00       	mov    $0x0,%eax
    279a:	e8 61 eb ff ff       	call   1300 <__isoc99_sscanf@plt>
    279f:	44 8b 44 24 3c       	mov    0x3c(%rsp),%r8d
    27a4:	41 81 f8 c8 00 00 00 	cmp    $0xc8,%r8d
    27ab:	0f 85 18 fd ff ff    	jne    24c9 <submitr+0x472>
    27b1:	48 8d 1d 5e 0d 00 00 	lea    0xd5e(%rip),%rbx        # 3516 <array.0+0x416>
    27b8:	48 8d bc 24 60 20 00 	lea    0x2060(%rsp),%rdi
    27bf:	00 
    27c0:	48 89 de             	mov    %rbx,%rsi
    27c3:	e8 d8 ea ff ff       	call   12a0 <strcmp@plt>
    27c8:	85 c0                	test   %eax,%eax
    27ca:	0f 84 30 fd ff ff    	je     2500 <submitr+0x4a9>
    27d0:	48 8d b4 24 60 20 00 	lea    0x2060(%rsp),%rsi
    27d7:	00 
    27d8:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
    27dd:	ba 00 20 00 00       	mov    $0x2000,%edx
    27e2:	e8 a4 f7 ff ff       	call   1f8b <rio_readlineb>
    27e7:	48 85 c0             	test   %rax,%rax
    27ea:	7f cc                	jg     27b8 <submitr+0x761>
    27ec:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    27f3:	3a 20 43 
    27f6:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    27fd:	20 75 6e 
    2800:	49 89 07             	mov    %rax,(%r15)
    2803:	49 89 57 08          	mov    %rdx,0x8(%r15)
    2807:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    280e:	74 6f 20 
    2811:	48 ba 72 65 61 64 20 	movabs $0x6165682064616572,%rdx
    2818:	68 65 61 
    281b:	49 89 47 10          	mov    %rax,0x10(%r15)
    281f:	49 89 57 18          	mov    %rdx,0x18(%r15)
    2823:	48 b8 64 65 72 73 20 	movabs $0x6f72662073726564,%rax
    282a:	66 72 6f 
    282d:	48 ba 6d 20 73 65 72 	movabs $0x726576726573206d,%rdx
    2834:	76 65 72 
    2837:	49 89 47 20          	mov    %rax,0x20(%r15)
    283b:	49 89 57 28          	mov    %rdx,0x28(%r15)
    283f:	41 c6 47 30 00       	movb   $0x0,0x30(%r15)
    2844:	44 89 e7             	mov    %r12d,%edi
    2847:	e8 24 ea ff ff       	call   1270 <close@plt>
    284c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2851:	e9 f1 fc ff ff       	jmp    2547 <submitr+0x4f0>
    2856:	e8 f5 e9 ff ff       	call   1250 <__stack_chk_fail@plt>

000000000000285b <init_timeout>:
    285b:	f3 0f 1e fa          	endbr64 
    285f:	85 ff                	test   %edi,%edi
    2861:	75 01                	jne    2864 <init_timeout+0x9>
    2863:	c3                   	ret    
    2864:	53                   	push   %rbx
    2865:	89 fb                	mov    %edi,%ebx
    2867:	48 8d 35 e7 f6 ff ff 	lea    -0x919(%rip),%rsi        # 1f55 <sigalrm_handler>
    286e:	bf 0e 00 00 00       	mov    $0xe,%edi
    2873:	e8 38 ea ff ff       	call   12b0 <signal@plt>
    2878:	85 db                	test   %ebx,%ebx
    287a:	b8 00 00 00 00       	mov    $0x0,%eax
    287f:	0f 49 c3             	cmovns %ebx,%eax
    2882:	89 c7                	mov    %eax,%edi
    2884:	e8 d7 e9 ff ff       	call   1260 <alarm@plt>
    2889:	5b                   	pop    %rbx
    288a:	c3                   	ret    

000000000000288b <init_driver>:
    288b:	f3 0f 1e fa          	endbr64 
    288f:	41 54                	push   %r12
    2891:	55                   	push   %rbp
    2892:	53                   	push   %rbx
    2893:	48 83 ec 20          	sub    $0x20,%rsp
    2897:	48 89 fd             	mov    %rdi,%rbp
    289a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    28a1:	00 00 
    28a3:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    28a8:	31 c0                	xor    %eax,%eax
    28aa:	be 01 00 00 00       	mov    $0x1,%esi
    28af:	bf 0d 00 00 00       	mov    $0xd,%edi
    28b4:	e8 f7 e9 ff ff       	call   12b0 <signal@plt>
    28b9:	be 01 00 00 00       	mov    $0x1,%esi
    28be:	bf 1d 00 00 00       	mov    $0x1d,%edi
    28c3:	e8 e8 e9 ff ff       	call   12b0 <signal@plt>
    28c8:	be 01 00 00 00       	mov    $0x1,%esi
    28cd:	bf 1d 00 00 00       	mov    $0x1d,%edi
    28d2:	e8 d9 e9 ff ff       	call   12b0 <signal@plt>
    28d7:	ba 00 00 00 00       	mov    $0x0,%edx
    28dc:	be 01 00 00 00       	mov    $0x1,%esi
    28e1:	bf 02 00 00 00       	mov    $0x2,%edi
    28e6:	e8 a5 ea ff ff       	call   1390 <socket@plt>
    28eb:	85 c0                	test   %eax,%eax
    28ed:	0f 88 9c 00 00 00    	js     298f <init_driver+0x104>
    28f3:	89 c3                	mov    %eax,%ebx
    28f5:	48 8d 3d 20 0c 00 00 	lea    0xc20(%rip),%rdi        # 351c <array.0+0x41c>
    28fc:	e8 bf e9 ff ff       	call   12c0 <gethostbyname@plt>
    2901:	48 85 c0             	test   %rax,%rax
    2904:	0f 84 d1 00 00 00    	je     29db <init_driver+0x150>
    290a:	49 89 e4             	mov    %rsp,%r12
    290d:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    2914:	00 
    2915:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    291c:	00 00 
    291e:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
    2924:	48 63 50 14          	movslq 0x14(%rax),%rdx
    2928:	48 8b 40 18          	mov    0x18(%rax),%rax
    292c:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
    2931:	b9 0c 00 00 00       	mov    $0xc,%ecx
    2936:	48 8b 30             	mov    (%rax),%rsi
    2939:	e8 92 e9 ff ff       	call   12d0 <__memmove_chk@plt>
    293e:	66 c7 44 24 02 3b 6e 	movw   $0x6e3b,0x2(%rsp)
    2945:	ba 10 00 00 00       	mov    $0x10,%edx
    294a:	4c 89 e6             	mov    %r12,%rsi
    294d:	89 df                	mov    %ebx,%edi
    294f:	e8 ec e9 ff ff       	call   1340 <connect@plt>
    2954:	85 c0                	test   %eax,%eax
    2956:	0f 88 e7 00 00 00    	js     2a43 <init_driver+0x1b8>
    295c:	89 df                	mov    %ebx,%edi
    295e:	e8 0d e9 ff ff       	call   1270 <close@plt>
    2963:	66 c7 45 00 4f 4b    	movw   $0x4b4f,0x0(%rbp)
    2969:	c6 45 02 00          	movb   $0x0,0x2(%rbp)
    296d:	b8 00 00 00 00       	mov    $0x0,%eax
    2972:	48 8b 54 24 18       	mov    0x18(%rsp),%rdx
    2977:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    297e:	00 00 
    2980:	0f 85 f5 00 00 00    	jne    2a7b <init_driver+0x1f0>
    2986:	48 83 c4 20          	add    $0x20,%rsp
    298a:	5b                   	pop    %rbx
    298b:	5d                   	pop    %rbp
    298c:	41 5c                	pop    %r12
    298e:	c3                   	ret    
    298f:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    2996:	3a 20 43 
    2999:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    29a0:	20 75 6e 
    29a3:	48 89 45 00          	mov    %rax,0x0(%rbp)
    29a7:	48 89 55 08          	mov    %rdx,0x8(%rbp)
    29ab:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    29b2:	74 6f 20 
    29b5:	48 ba 63 72 65 61 74 	movabs $0x7320657461657263,%rdx
    29bc:	65 20 73 
    29bf:	48 89 45 10          	mov    %rax,0x10(%rbp)
    29c3:	48 89 55 18          	mov    %rdx,0x18(%rbp)
    29c7:	c7 45 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%rbp)
    29ce:	66 c7 45 24 74 00    	movw   $0x74,0x24(%rbp)
    29d4:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    29d9:	eb 97                	jmp    2972 <init_driver+0xe7>
    29db:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
    29e2:	3a 20 44 
    29e5:	48 ba 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rdx
    29ec:	20 75 6e 
    29ef:	48 89 45 00          	mov    %rax,0x0(%rbp)
    29f3:	48 89 55 08          	mov    %rdx,0x8(%rbp)
    29f7:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    29fe:	74 6f 20 
    2a01:	48 ba 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rdx
    2a08:	76 65 20 
    2a0b:	48 89 45 10          	mov    %rax,0x10(%rbp)
    2a0f:	48 89 55 18          	mov    %rdx,0x18(%rbp)
    2a13:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
    2a1a:	72 20 61 
    2a1d:	48 89 45 20          	mov    %rax,0x20(%rbp)
    2a21:	c7 45 28 64 64 72 65 	movl   $0x65726464,0x28(%rbp)
    2a28:	66 c7 45 2c 73 73    	movw   $0x7373,0x2c(%rbp)
    2a2e:	c6 45 2e 00          	movb   $0x0,0x2e(%rbp)
    2a32:	89 df                	mov    %ebx,%edi
    2a34:	e8 37 e8 ff ff       	call   1270 <close@plt>
    2a39:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2a3e:	e9 2f ff ff ff       	jmp    2972 <init_driver+0xe7>
    2a43:	4c 8d 05 d2 0a 00 00 	lea    0xad2(%rip),%r8        # 351c <array.0+0x41c>
    2a4a:	48 8d 0d 87 0a 00 00 	lea    0xa87(%rip),%rcx        # 34d8 <array.0+0x3d8>
    2a51:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    2a58:	be 01 00 00 00       	mov    $0x1,%esi
    2a5d:	48 89 ef             	mov    %rbp,%rdi
    2a60:	b8 00 00 00 00       	mov    $0x0,%eax
    2a65:	e8 16 e9 ff ff       	call   1380 <__sprintf_chk@plt>
    2a6a:	89 df                	mov    %ebx,%edi
    2a6c:	e8 ff e7 ff ff       	call   1270 <close@plt>
    2a71:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2a76:	e9 f7 fe ff ff       	jmp    2972 <init_driver+0xe7>
    2a7b:	e8 d0 e7 ff ff       	call   1250 <__stack_chk_fail@plt>

0000000000002a80 <driver_post>:
    2a80:	f3 0f 1e fa          	endbr64 
    2a84:	53                   	push   %rbx
    2a85:	4c 89 c3             	mov    %r8,%rbx
    2a88:	85 c9                	test   %ecx,%ecx
    2a8a:	75 17                	jne    2aa3 <driver_post+0x23>
    2a8c:	48 85 ff             	test   %rdi,%rdi
    2a8f:	74 05                	je     2a96 <driver_post+0x16>
    2a91:	80 3f 00             	cmpb   $0x0,(%rdi)
    2a94:	75 33                	jne    2ac9 <driver_post+0x49>
    2a96:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
    2a9b:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
    2a9f:	89 c8                	mov    %ecx,%eax
    2aa1:	5b                   	pop    %rbx
    2aa2:	c3                   	ret    
    2aa3:	48 8d 35 8a 0a 00 00 	lea    0xa8a(%rip),%rsi        # 3534 <array.0+0x434>
    2aaa:	bf 01 00 00 00       	mov    $0x1,%edi
    2aaf:	b8 00 00 00 00       	mov    $0x0,%eax
    2ab4:	e8 57 e8 ff ff       	call   1310 <__printf_chk@plt>
    2ab9:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
    2abe:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
    2ac2:	b8 00 00 00 00       	mov    $0x0,%eax
    2ac7:	eb d8                	jmp    2aa1 <driver_post+0x21>
    2ac9:	41 50                	push   %r8
    2acb:	52                   	push   %rdx
    2acc:	4c 8d 0d 78 0a 00 00 	lea    0xa78(%rip),%r9        # 354b <array.0+0x44b>
    2ad3:	49 89 f0             	mov    %rsi,%r8
    2ad6:	48 89 f9             	mov    %rdi,%rcx
    2ad9:	48 8d 15 73 0a 00 00 	lea    0xa73(%rip),%rdx        # 3553 <array.0+0x453>
    2ae0:	be 6e 3b 00 00       	mov    $0x3b6e,%esi
    2ae5:	48 8d 3d 30 0a 00 00 	lea    0xa30(%rip),%rdi        # 351c <array.0+0x41c>
    2aec:	e8 66 f5 ff ff       	call   2057 <submitr>
    2af1:	48 83 c4 10          	add    $0x10,%rsp
    2af5:	eb aa                	jmp    2aa1 <driver_post+0x21>

Disassembly of section .fini:

0000000000002af8 <_fini>:
    2af8:	f3 0f 1e fa          	endbr64 
    2afc:	48 83 ec 08          	sub    $0x8,%rsp
    2b00:	48 83 c4 08          	add    $0x8,%rsp
    2b04:	c3                   	ret    