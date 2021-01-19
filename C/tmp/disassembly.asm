
ex9:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8d 05 a1 01 00 00 	lea    0x1a1(%rip),%rax        # 11b0 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 4a 2f 00 00    	pushq  0x2f4a(%rip)        # 3f70 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 4b 2f 00 00 	bnd jmpq *0x2f4b(%rip)        # 3f78 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	pushq  $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmpq 1020 <.plt>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	pushq  $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmpq 1020 <.plt>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	pushq  $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmpq 1020 <.plt>
    10bf:	90                   	nop
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	68 09 00 00 00       	pushq  $0x9
    10c9:	f2 e9 51 ff ff ff    	bnd jmpq 1020 <.plt>
    10cf:	90                   	nop

Disassembly of section .plt.got:

00000000000010d0 <__cxa_finalize@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 1d 2f 00 00 	bnd jmpq *0x2f1d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    10db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

00000000000010e0 <free@plt>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	f2 ff 25 95 2e 00 00 	bnd jmpq *0x2e95(%rip)        # 3f80 <free@GLIBC_2.2.5>
    10eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010f0 <putchar@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 8d 2e 00 00 	bnd jmpq *0x2e8d(%rip)        # 3f88 <putchar@GLIBC_2.2.5>
    10fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001100 <__stack_chk_fail@plt>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	f2 ff 25 85 2e 00 00 	bnd jmpq *0x2e85(%rip)        # 3f90 <__stack_chk_fail@GLIBC_2.4>
    110b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001110 <printf@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 7d 2e 00 00 	bnd jmpq *0x2e7d(%rip)        # 3f98 <printf@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001120 <srand@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 75 2e 00 00 	bnd jmpq *0x2e75(%rip)        # 3fa0 <srand@GLIBC_2.2.5>
    112b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001130 <__monstartup@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 6d 2e 00 00 	bnd jmpq *0x2e6d(%rip)        # 3fa8 <__monstartup@GLIBC_2.2.5>
    113b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001140 <time@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 65 2e 00 00 	bnd jmpq *0x2e65(%rip)        # 3fb0 <time@GLIBC_2.2.5>
    114b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001150 <malloc@plt>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	f2 ff 25 5d 2e 00 00 	bnd jmpq *0x2e5d(%rip)        # 3fb8 <malloc@GLIBC_2.2.5>
    115b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001160 <__cxa_atexit@plt>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	f2 ff 25 55 2e 00 00 	bnd jmpq *0x2e55(%rip)        # 3fc0 <__cxa_atexit@GLIBC_2.2.5>
    116b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001170 <rand@plt>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	f2 ff 25 4d 2e 00 00 	bnd jmpq *0x2e4d(%rip)        # 3fc8 <rand@GLIBC_2.2.5>
    117b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001180 <_start>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	31 ed                	xor    %ebp,%ebp
    1186:	49 89 d1             	mov    %rdx,%r9
    1189:	5e                   	pop    %rsi
    118a:	48 89 e2             	mov    %rsp,%rdx
    118d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1191:	50                   	push   %rax
    1192:	54                   	push   %rsp
    1193:	4c 8d 05 a6 03 00 00 	lea    0x3a6(%rip),%r8        # 1540 <__libc_csu_fini>
    119a:	48 8d 0d 2f 03 00 00 	lea    0x32f(%rip),%rcx        # 14d0 <__libc_csu_init>
    11a1:	48 8d 3d 21 01 00 00 	lea    0x121(%rip),%rdi        # 12c9 <main>
    11a8:	ff 15 32 2e 00 00    	callq  *0x2e32(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    11ae:	f4                   	hlt    
    11af:	90                   	nop

00000000000011b0 <__gmon_start__>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	8b 05 56 2e 00 00    	mov    0x2e56(%rip),%eax        # 4010 <__TMC_END__>
    11ba:	85 c0                	test   %eax,%eax
    11bc:	74 02                	je     11c0 <__gmon_start__+0x10>
    11be:	c3                   	retq   
    11bf:	90                   	nop
    11c0:	48 83 ec 08          	sub    $0x8,%rsp
    11c4:	48 8d 3d b5 ff ff ff 	lea    -0x4b(%rip),%rdi        # 1180 <_start>
    11cb:	48 8d 35 9f 03 00 00 	lea    0x39f(%rip),%rsi        # 1571 <etext>
    11d2:	c7 05 34 2e 00 00 01 	movl   $0x1,0x2e34(%rip)        # 4010 <__TMC_END__>
    11d9:	00 00 00 
    11dc:	e8 4f ff ff ff       	callq  1130 <__monstartup@plt>
    11e1:	48 8b 3d f0 2d 00 00 	mov    0x2df0(%rip),%rdi        # 3fd8 <_mcleanup@GLIBC_2.2.5>
    11e8:	48 83 c4 08          	add    $0x8,%rsp
    11ec:	e9 5f 03 00 00       	jmpq   1550 <atexit>
    11f1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    11f8:	00 00 00 
    11fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001200 <_dl_relocate_static_pie>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	c3                   	retq   
    1205:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    120c:	00 00 00 
    120f:	90                   	nop

0000000000001210 <deregister_tm_clones>:
    1210:	48 8d 3d f9 2d 00 00 	lea    0x2df9(%rip),%rdi        # 4010 <__TMC_END__>
    1217:	48 8d 05 f2 2d 00 00 	lea    0x2df2(%rip),%rax        # 4010 <__TMC_END__>
    121e:	48 39 f8             	cmp    %rdi,%rax
    1221:	74 15                	je     1238 <deregister_tm_clones+0x28>
    1223:	48 8b 05 a6 2d 00 00 	mov    0x2da6(%rip),%rax        # 3fd0 <_ITM_deregisterTMCloneTable>
    122a:	48 85 c0             	test   %rax,%rax
    122d:	74 09                	je     1238 <deregister_tm_clones+0x28>
    122f:	ff e0                	jmpq   *%rax
    1231:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1238:	c3                   	retq   
    1239:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001240 <register_tm_clones>:
    1240:	48 8d 3d c9 2d 00 00 	lea    0x2dc9(%rip),%rdi        # 4010 <__TMC_END__>
    1247:	48 8d 35 c2 2d 00 00 	lea    0x2dc2(%rip),%rsi        # 4010 <__TMC_END__>
    124e:	48 29 fe             	sub    %rdi,%rsi
    1251:	48 89 f0             	mov    %rsi,%rax
    1254:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1258:	48 c1 f8 03          	sar    $0x3,%rax
    125c:	48 01 c6             	add    %rax,%rsi
    125f:	48 d1 fe             	sar    %rsi
    1262:	74 14                	je     1278 <register_tm_clones+0x38>
    1264:	48 8b 05 85 2d 00 00 	mov    0x2d85(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    126b:	48 85 c0             	test   %rax,%rax
    126e:	74 08                	je     1278 <register_tm_clones+0x38>
    1270:	ff e0                	jmpq   *%rax
    1272:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1278:	c3                   	retq   
    1279:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001280 <__do_global_dtors_aux>:
    1280:	f3 0f 1e fa          	endbr64 
    1284:	80 3d 89 2d 00 00 00 	cmpb   $0x0,0x2d89(%rip)        # 4014 <completed.8059>
    128b:	75 2b                	jne    12b8 <__do_global_dtors_aux+0x38>
    128d:	55                   	push   %rbp
    128e:	48 83 3d 62 2d 00 00 	cmpq   $0x0,0x2d62(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1295:	00 
    1296:	48 89 e5             	mov    %rsp,%rbp
    1299:	74 0c                	je     12a7 <__do_global_dtors_aux+0x27>
    129b:	48 8b 3d 66 2d 00 00 	mov    0x2d66(%rip),%rdi        # 4008 <__dso_handle>
    12a2:	e8 29 fe ff ff       	callq  10d0 <__cxa_finalize@plt>
    12a7:	e8 64 ff ff ff       	callq  1210 <deregister_tm_clones>
    12ac:	c6 05 61 2d 00 00 01 	movb   $0x1,0x2d61(%rip)        # 4014 <completed.8059>
    12b3:	5d                   	pop    %rbp
    12b4:	c3                   	retq   
    12b5:	0f 1f 00             	nopl   (%rax)
    12b8:	c3                   	retq   
    12b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012c0 <frame_dummy>:
    12c0:	f3 0f 1e fa          	endbr64 
    12c4:	e9 77 ff ff ff       	jmpq   1240 <register_tm_clones>

00000000000012c9 <main>:
    12c9:	f3 0f 1e fa          	endbr64 
    12cd:	55                   	push   %rbp
    12ce:	48 89 e5             	mov    %rsp,%rbp
    12d1:	48 83 ec 30          	sub    $0x30,%rsp
    12d5:	ff 15 0d 2d 00 00    	callq  *0x2d0d(%rip)        # 3fe8 <mcount@GLIBC_2.2.5>
    12db:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    12e2:	00 00 
    12e4:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    12e8:	31 c0                	xor    %eax,%eax
    12ea:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
    12ee:	48 89 c7             	mov    %rax,%rdi
    12f1:	b8 00 00 00 00       	mov    $0x0,%eax
    12f6:	e8 45 fe ff ff       	callq  1140 <time@plt>
    12fb:	89 c7                	mov    %eax,%edi
    12fd:	e8 1e fe ff ff       	callq  1120 <srand@plt>
    1302:	bf 3c 01 00 00       	mov    $0x13c,%edi
    1307:	e8 44 fe ff ff       	callq  1150 <malloc@plt>
    130c:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1310:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1314:	c7 00 00 00 00 00    	movl   $0x0,(%rax)
    131a:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
    1321:	eb 25                	jmp    1348 <main+0x7f>
    1323:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1327:	8b 08                	mov    (%rax),%ecx
    1329:	8b 45 d8             	mov    -0x28(%rbp),%eax
    132c:	48 98                	cltq   
    132e:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1335:	00 
    1336:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    133a:	48 01 d0             	add    %rdx,%rax
    133d:	8b 55 d8             	mov    -0x28(%rbp),%edx
    1340:	01 ca                	add    %ecx,%edx
    1342:	89 10                	mov    %edx,(%rax)
    1344:	83 45 d8 01          	addl   $0x1,-0x28(%rbp)
    1348:	83 7d d8 4e          	cmpl   $0x4e,-0x28(%rbp)
    134c:	7e d5                	jle    1323 <main+0x5a>
    134e:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
    1355:	e9 b9 00 00 00       	jmpq   1413 <main+0x14a>
    135a:	e8 11 fe ff ff       	callq  1170 <rand@plt>
    135f:	48 63 d0             	movslq %eax,%rdx
    1362:	48 69 d2 55 3a b2 67 	imul   $0x67b23a55,%rdx,%rdx
    1369:	48 c1 ea 20          	shr    $0x20,%rdx
    136d:	89 d1                	mov    %edx,%ecx
    136f:	c1 f9 05             	sar    $0x5,%ecx
    1372:	99                   	cltd   
    1373:	29 d1                	sub    %edx,%ecx
    1375:	89 ca                	mov    %ecx,%edx
    1377:	89 55 dc             	mov    %edx,-0x24(%rbp)
    137a:	8b 55 dc             	mov    -0x24(%rbp),%edx
    137d:	6b d2 4f             	imul   $0x4f,%edx,%edx
    1380:	29 d0                	sub    %edx,%eax
    1382:	89 45 dc             	mov    %eax,-0x24(%rbp)
    1385:	e8 e6 fd ff ff       	callq  1170 <rand@plt>
    138a:	48 63 d0             	movslq %eax,%rdx
    138d:	48 69 d2 55 3a b2 67 	imul   $0x67b23a55,%rdx,%rdx
    1394:	48 c1 ea 20          	shr    $0x20,%rdx
    1398:	89 d1                	mov    %edx,%ecx
    139a:	c1 f9 05             	sar    $0x5,%ecx
    139d:	99                   	cltd   
    139e:	29 d1                	sub    %edx,%ecx
    13a0:	89 ca                	mov    %ecx,%edx
    13a2:	89 55 e0             	mov    %edx,-0x20(%rbp)
    13a5:	8b 55 e0             	mov    -0x20(%rbp),%edx
    13a8:	6b d2 4f             	imul   $0x4f,%edx,%edx
    13ab:	29 d0                	sub    %edx,%eax
    13ad:	89 45 e0             	mov    %eax,-0x20(%rbp)
    13b0:	8b 45 dc             	mov    -0x24(%rbp),%eax
    13b3:	48 98                	cltq   
    13b5:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    13bc:	00 
    13bd:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    13c1:	48 01 d0             	add    %rdx,%rax
    13c4:	8b 00                	mov    (%rax),%eax
    13c6:	89 45 e4             	mov    %eax,-0x1c(%rbp)
    13c9:	8b 45 e0             	mov    -0x20(%rbp),%eax
    13cc:	48 98                	cltq   
    13ce:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    13d5:	00 
    13d6:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    13da:	48 01 d0             	add    %rdx,%rax
    13dd:	8b 55 dc             	mov    -0x24(%rbp),%edx
    13e0:	48 63 d2             	movslq %edx,%rdx
    13e3:	48 8d 0c 95 00 00 00 	lea    0x0(,%rdx,4),%rcx
    13ea:	00 
    13eb:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    13ef:	48 01 ca             	add    %rcx,%rdx
    13f2:	8b 00                	mov    (%rax),%eax
    13f4:	89 02                	mov    %eax,(%rdx)
    13f6:	8b 45 e0             	mov    -0x20(%rbp),%eax
    13f9:	48 98                	cltq   
    13fb:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1402:	00 
    1403:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1407:	48 01 c2             	add    %rax,%rdx
    140a:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    140d:	89 02                	mov    %eax,(%rdx)
    140f:	83 45 d8 01          	addl   $0x1,-0x28(%rbp)
    1413:	81 7d d8 3f 42 0f 00 	cmpl   $0xf423f,-0x28(%rbp)
    141a:	0f 8e 3a ff ff ff    	jle    135a <main+0x91>
    1420:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
    1424:	48 89 c7             	mov    %rax,%rdi
    1427:	b8 00 00 00 00       	mov    $0x0,%eax
    142c:	e8 0f fd ff ff       	callq  1140 <time@plt>
    1431:	89 c7                	mov    %eax,%edi
    1433:	e8 e8 fc ff ff       	callq  1120 <srand@plt>
    1438:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
    143f:	eb 58                	jmp    1499 <main+0x1d0>
    1441:	e8 2a fd ff ff       	callq  1170 <rand@plt>
    1446:	48 63 d0             	movslq %eax,%rdx
    1449:	48 69 d2 55 3a b2 67 	imul   $0x67b23a55,%rdx,%rdx
    1450:	48 c1 ea 20          	shr    $0x20,%rdx
    1454:	89 d1                	mov    %edx,%ecx
    1456:	c1 f9 05             	sar    $0x5,%ecx
    1459:	99                   	cltd   
    145a:	29 d1                	sub    %edx,%ecx
    145c:	89 ca                	mov    %ecx,%edx
    145e:	89 55 dc             	mov    %edx,-0x24(%rbp)
    1461:	8b 55 dc             	mov    -0x24(%rbp),%edx
    1464:	6b d2 4f             	imul   $0x4f,%edx,%edx
    1467:	29 d0                	sub    %edx,%eax
    1469:	89 45 dc             	mov    %eax,-0x24(%rbp)
    146c:	8b 45 dc             	mov    -0x24(%rbp),%eax
    146f:	48 98                	cltq   
    1471:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1478:	00 
    1479:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    147d:	48 01 d0             	add    %rdx,%rax
    1480:	8b 00                	mov    (%rax),%eax
    1482:	89 c6                	mov    %eax,%esi
    1484:	48 8d 3d 79 0b 00 00 	lea    0xb79(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    148b:	b8 00 00 00 00       	mov    $0x0,%eax
    1490:	e8 7b fc ff ff       	callq  1110 <printf@plt>
    1495:	83 45 d8 01          	addl   $0x1,-0x28(%rbp)
    1499:	83 7d d8 05          	cmpl   $0x5,-0x28(%rbp)
    149d:	7e a2                	jle    1441 <main+0x178>
    149f:	bf 0a 00 00 00       	mov    $0xa,%edi
    14a4:	e8 47 fc ff ff       	callq  10f0 <putchar@plt>
    14a9:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    14ad:	48 89 c7             	mov    %rax,%rdi
    14b0:	e8 2b fc ff ff       	callq  10e0 <free@plt>
    14b5:	b8 00 00 00 00       	mov    $0x0,%eax
    14ba:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
    14be:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
    14c5:	00 00 
    14c7:	74 05                	je     14ce <main+0x205>
    14c9:	e8 32 fc ff ff       	callq  1100 <__stack_chk_fail@plt>
    14ce:	c9                   	leaveq 
    14cf:	c3                   	retq   

00000000000014d0 <__libc_csu_init>:
    14d0:	f3 0f 1e fa          	endbr64 
    14d4:	41 57                	push   %r15
    14d6:	4c 8d 3d 8b 28 00 00 	lea    0x288b(%rip),%r15        # 3d68 <__frame_dummy_init_array_entry>
    14dd:	41 56                	push   %r14
    14df:	49 89 d6             	mov    %rdx,%r14
    14e2:	41 55                	push   %r13
    14e4:	49 89 f5             	mov    %rsi,%r13
    14e7:	41 54                	push   %r12
    14e9:	41 89 fc             	mov    %edi,%r12d
    14ec:	55                   	push   %rbp
    14ed:	48 8d 2d 7c 28 00 00 	lea    0x287c(%rip),%rbp        # 3d70 <__do_global_dtors_aux_fini_array_entry>
    14f4:	53                   	push   %rbx
    14f5:	4c 29 fd             	sub    %r15,%rbp
    14f8:	48 83 ec 08          	sub    $0x8,%rsp
    14fc:	e8 ff fa ff ff       	callq  1000 <_init>
    1501:	48 c1 fd 03          	sar    $0x3,%rbp
    1505:	74 1f                	je     1526 <__libc_csu_init+0x56>
    1507:	31 db                	xor    %ebx,%ebx
    1509:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1510:	4c 89 f2             	mov    %r14,%rdx
    1513:	4c 89 ee             	mov    %r13,%rsi
    1516:	44 89 e7             	mov    %r12d,%edi
    1519:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    151d:	48 83 c3 01          	add    $0x1,%rbx
    1521:	48 39 dd             	cmp    %rbx,%rbp
    1524:	75 ea                	jne    1510 <__libc_csu_init+0x40>
    1526:	48 83 c4 08          	add    $0x8,%rsp
    152a:	5b                   	pop    %rbx
    152b:	5d                   	pop    %rbp
    152c:	41 5c                	pop    %r12
    152e:	41 5d                	pop    %r13
    1530:	41 5e                	pop    %r14
    1532:	41 5f                	pop    %r15
    1534:	c3                   	retq   
    1535:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    153c:	00 00 00 00 

0000000000001540 <__libc_csu_fini>:
    1540:	f3 0f 1e fa          	endbr64 
    1544:	c3                   	retq   
    1545:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    154c:	00 00 00 
    154f:	90                   	nop

0000000000001550 <atexit>:
    1550:	f3 0f 1e fa          	endbr64 
    1554:	48 8b 15 ad 2a 00 00 	mov    0x2aad(%rip),%rdx        # 4008 <__dso_handle>
    155b:	31 f6                	xor    %esi,%esi
    155d:	e9 fe fb ff ff       	jmpq   1160 <__cxa_atexit@plt>

Disassembly of section .fini:

0000000000001564 <_fini>:
    1564:	f3 0f 1e fa          	endbr64 
    1568:	48 83 ec 08          	sub    $0x8,%rsp
    156c:	48 83 c4 08          	add    $0x8,%rsp
    1570:	c3                   	retq   
