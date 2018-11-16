.data

	str: .asciiz "==========================Menu==========================="
	tb1: .asciiz "\nNhap ngay DAY:"
	tb2: .asciiz "\nNhap thang MONTH:"
	tb3: .asciiz "\nNhap nam YEAR:"
	tb4: .asciiz "\n-----Ban hay chon 1 trong nhung thao tac duoi day-----"
	op1: .asciiz "\n1.Xuat chuoi TIME theo dinh dang DD/MM/YYYY"
	op2: .asciiz "\n2.Chuyen doi chuoi TIME thanh mot trong nhung dinh dang sau:"
	op21: .asciiz "	\nA. MM/DD/YYYY: "
	op22: .asciiz "	\nB. Month DD, YYYY: "
	op23: .asciiz " \nC. DD Month, YYYY: "
	op3: .asciiz "\n3.Cho biet ngay xua nhap la ngay thu may trong tuan: "
	op4: .asciiz "\n4.Kiem tra nam trong chuoi TIME co phai la nam nhuan hay khong(1-nam nhuan, 0-khong phai nam nhuan): "
	op5: .asciiz "\n5.Cho biet khoang thoi gian giua chuoi TIME_1 va TIME_2: "
	op6: .asciiz "\n6.Cho biet 2 nam nhuan gan nhat voi nam trong chuoi TIME: "
	op7: .asciiz "\n7.Kiem tra bo du lieu dau vao khi nhap, neu du lieu khong hop le thi yeu cau nguoi dung nhap lai(tu kiem tra trong luc nhap)."
	tb5: .asciiz "\nLua chon: "
	tb6: .asciiz "\nKet qua: "
	chuoi_ngay: .space 10
	chuoi_thang: .space 10
	chuoi_nam: .space 10
	Time: .space 15
	Time_2: .space 15
	op24: .asciiz "\nChon dinh dang (A or B or C): "
	tb1_2: .asciiz "\nNhap ngay DAY(Time 2):"
	tb2_2: .asciiz "\nNhap thang MONTH(Time 2):"
	tb3_2: .asciiz "\nNhap nam YEAR(Time 2):"
	lcl: .asciiz "Nhap lai lua chon: "
	nhaplai: .asciiz "Du lieu khong hop le! Xin moi nhap lai: "
	T2:.asciiz "Monday"
	T3:.asciiz "Tuesday"
	T4:.asciiz "Wednesday"
	T5:.asciiz "Thursday"
	T6:.asciiz "Friday"
	T7:.asciiz "Saturday"
	CN:.asciiz "Sunday"
.text
	.globl main
main:

Menu:

	#Hien Menu
	la $a0,str
	addi $v0,$0,4
	syscall
Nhap:
	la $a0,tb1
	addi $v0,$0,4
	syscall
	#ham nhap ngay
	la $a0,chuoi_ngay
	addi $v0,$0,8
	addi $a1,$0,10
	syscall
	la $a0,tb2
	addi $v0,$0,4
	syscall
	#ham nhap thang
	la $a0,chuoi_thang
	addi $v0,$0,8
	addi $a1,$0,10
	syscall
	la $a0,tb3
	addi $v0,$0,4
	syscall
	#ham nhap nam
	la $a0,chuoi_nam
	addi $v0,$0,8
	addi $a1,$0,10
	syscall
KiemTra:
	#Kiem tra ki tu
	la $a0,chuoi_ngay
	la $a1,chuoi_thang
	la $a2,chuoi_nam
	jal KiemTraKiTu
	beq $v0,$0,NhapLai
	#Kiem tra so
	la $a0,chuoi_ngay
	jal atoi
	addi $t0,$v0,0
	la $a0,chuoi_thang
	jal atoi
	addi $t1,$v0,0
	la $a0,chuoi_nam
	jal atoi
	addi $t2,$v0,0
	addi $a0,$t0,0
	addi $a1,$t1,0
	addi $a2,$t2,0
	jal KiemTraSo
	beq $v0,$0,NhapLai
	#In Ra Bang Thao Tac
	la $a0,tb4
	addi $v0,$0,4
	syscall
	la $a0,op1
	addi $v0,$0,4
	syscall
	la $a0,op2
	syscall
	la $a0,op21
	syscall
	la $a0,op22
	syscall
	la $a0,op23
	syscall
	la $a0,op3
	syscall
	la $a0,op4
	syscall
	la $a0,op5
	syscall
	la $a0,op6
	syscall
	la $a0,op7
	syscall
	la $a0,tb5
	syscall

TaoChuoiTime:			#Tao chuoi tu  Char* Time tu input
	la $a0,chuoi_ngay
	jal atoi
	addi $t0,$v0,0
	la $a0,chuoi_thang
	jal atoi
	addi $t1,$v0,0
	la $a0,chuoi_nam
	jal atoi
	addi $t2,$v0,0
	addi $a0,$t0,0		#a0 = ngay
	addi $a1,$t1,0		#a1 = thang
	addi $a2,$t2,0		#a2 = nam
	la $a3,Time		#a3 la chuoi de luu Time
	jal Date
	addi $v1,$v0,0		#v1 giu chuoi Time nhap vao.
ThaoTac:	#chon thao tac
	addi $v0,$0,5
	syscall
	addi $s0,$v0,0
	#switch case:
	addi $t3,$0,1
	beq $s0,1,OP1
	addi $t3,$t3,1
	beq $s0,2,OP2
	addi $t3,$t3,1
	beq $s0,3,OP3
	addi $t3,$t3,1
	beq $s0,4,OP4
	addi $t3,$t3,1
	beq $s0,5,OP5
	addi $t3,$t3,1
	beq $s0,6,OP6
	la $a0,lcl
	addi $v0,$0,4
	syscall
	j ThaoTac
OP1:

#Code
	addi $t0,$v1,0		#t0 giu chuoi Time
	la $a0,tb6
	addi $v0,$0,4
	syscall
	addi $a0,$t0,0
	addi $v0,$0,4
	syscall
	j End

OP2:

#Code
	addi $t0,$v1,0		#t0 giu chuoi Time
	la $a0,op24
	addi $v0,$0,4
	syscall
	addi $v0,$0,12
	syscall
	addi $a0,$t0,0
	addi $a1,$v0,0
	jal Convert
	addi $t0,$v0,0
	la $a0,tb6
	addi $v0,$0,4
	syscall
	addi $a0,$t0,0
	syscall
	j End

OP3:

#Code
	la $a0,tb6		#In ra str Ket qua:
	addi $v0,$0,4
	syscall
	#
	addi $a0,$v1,0
	jal Day		#Lay ngay
	addi $t0,$v0,0
	addi $a0,$v1,0
	jal Month	#Lay thang
	addi $t1,$v0,0
	addi $a0,$v1,0
	jal Year	#Lay nam
	addi $t2,$v0,0
	
	addi $a0,$t0,0		#ngay
	addi $a1,$t1,0		#thang
	addi $a2,$t2,0		#nam
	jal weekday
	addi $t1,$0,0
	beq $v0,$0,D6
	addi $t1,$t1,1
	beq $v0,$t1,D0
	addi $t1,$t1,1
	beq $v0,$t1,D1
	addi $t1,$t1,1
	beq $v0,$t1,D2
	addi $t1,$t1,1
	beq $v0,$t1,D3
	addi $t1,$t1,1
	beq $v0,$t1,D4
	j D5
D0:
	li $v0,4
	la $a0,CN
	syscall
	j KetThuc_OP3
D1:
	li $v0,4
	la $a0,T2
	syscall
	j KetThuc_OP3
D2:
	li $v0,4
	la $a0,T3
	syscall
	j KetThuc_OP3
D3:
	li $v0,4
	la $a0,T4
	syscall
	j KetThuc_OP3
D4:
	li $v0,4
	la $a0,T5
	syscall
	j KetThuc_OP3
D5:
	li $v0,4
	la $a0,T6
	syscall
	j KetThuc_OP3
D6:
	li $v0,4
	la $a0,T7
	syscall
	#
KetThuc_OP3:
	j End

OP4:

#Code
	addi $a0,$v1,0		#dua chuoi Time vao a0
	jal Year
	addi $a0,$v0,0
	jal LeapYear
	addi $t0,$v0,0
	la $a0,tb6
	addi $v0,$0,4
	syscall
	addi $a0,$t0,0
	addi $v0,$0,1
	syscall
	j End

OP5:

#Code
	#Luu Time 1 vao s0
	addi $s0,$v1,0
	#Nhap ngay, thang, nam Time2
	la $a0,tb1_2
	addi $v0,$0,4
	syscall
	#ham nhao ngay
	la $a0,chuoi_ngay
	addi $v0,$0,8
	addi $a1,$0,10
	syscall
	la $a0,tb2_2
	addi $v0,$0,4
	syscall
	#ham nhap thang
	la $a0,chuoi_thang
	addi $v0,$0,8
	addi $a1,$0,10
	syscall
	la $a0,tb3_2
	addi $v0,$0,4
	syscall
	#ham nhap nam
	la $a0,chuoi_nam
	addi $v0,$0,8
	addi $a1,$0,10
	syscall
	#Luu bien dua vao Date
	la $a0,chuoi_ngay
	jal atoi
	addi $t0,$v0,0
	la $a0,chuoi_thang
	jal atoi
	addi $t1,$v0,0
	la $a0,chuoi_nam
	jal atoi
	addi $t2,$v0,0
	addi $a0,$t0,0		#a0 = ngay
	addi $a1,$t1,0		#a1 = thang
	addi $a2,$t2,0		#a2 = nam
	la $a3,Time_2
	jal Date
	addi $s1,$v0,0		#luu chuoi Time 2 vao s1
	#
	addi $a0,$s0,0
	addi $a1,$s1,0
	jal KhoangCach
	#
	addi $t0,$v0,0
	la $a0,tb6
	addi $v0,$0,4
	syscall
	addi $a0,$t0,0
	addi $v0,$0,1
	syscall
	#
	j End

OP6:

#Code
	addi $a0,$v1,0		#dua chuoi Time vao a0
	jal Year
	addi $a0,$v0,0
	jal namnhuanlienke
	j End

OP7:

#Code



	j End

End:
#Ket qua
	addi $v0,$0,10
	syscall


#Ham chuyen chuoi -> int
atoi:
	addiu $sp, $sp, -12
	sw $t0, 0($sp)
	sw $t1, 4($sp)
	sw $t2, 8($sp)
	addi $v0, $0,0				# result = 0
	addi $t0, $a0, 0				# it = num
	lb $t1, 0($t0)				# c = *it
atoi_forloop:
	slti $t3, $t1, 48			# if (c < 48)
	bne $t3, $0, atoi_endfunc		#	jump to atoi_error
	slti $t3, $t1, 58			# if (c >= 58)
	beq $t3, $0, atoi_endfunc		#	jump to atoi_error
	addi $t1, $t1, -48
	addi $t3, $0, 10				# temp = 10
	mult $v0, $t3				# result = ...
	mflo $v0				# 	result * temp
	add $v0, $v0, $t1			# result += t1
	addi $t0, $t0, 1			# ++it
	lb $t1, 0($t0)				# c = *it
	j atoi_forloop
atoi_endfunc:
	# Restore the stack
	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $t2, 8($sp)
	addiu $sp, $sp, 12
	# Jump back to where it was called
	jr $ra
	
Date:
addi $sp, $sp, -12
sw $t0, 0($sp)
sw $t4, 4($sp)
sw $s0, 8($sp)
#NGAY
addi $t0,$0,10
div $a0, $t0
mflo $t4
addi $t0, $t4, 48
sb $t0, 0($a3)
mfhi $t4
addi $t0, $t4, 48
sb $t0, 1($a3)
addi $t0,$0,47
sb $t0, 2($a3)

#THANG
addi $t0,$0,10
div $a1, $t0
mflo $t4
addi $t0, $t4, 48
sb $t0, 3($a3)
mfhi $t4
addi $t0, $t4, 48
sb $t0, 4($a3)
addi $t0,$0,47
sb $t0, 5($a3)

#NAM
addi $t0,$0,1000
div $a2, $t0
mflo $t4
addi $t0, $t4, 48
sb $t0, 6($a3)
addi $t0,$0,100
mfhi $t4
div $t4, $t0
mflo $t4
addi $t0, $t4, 48
sb $t0, 7($a3)
addi $t0,$0,10
mfhi $t4
div $t4, $t0
mflo $t4
addi $t0, $t4, 48
sb $t0, 8($a3)
mfhi $t4
addi $t0, $t4, 48
sb $t0, 9($a3)
lw $t0, 0($sp)
lw $t4, 4($sp)
lw $s0, 8($sp)
addi $sp,$sp, 12
addi $v0,$a3,0
jr $ra


#kiem tra nam nhuan
LeapYear:
	addi $sp,$sp,-16
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	addi $t0,$0,4
	addi $t1,$0,100
	addi $t2,$0,400
	div $a0,$t2
	mfhi $t3
	beq $t3,$0,L1
	div $a0,$t1
	mfhi $t3
	beq $t3,$0,L2
	div $a0,$t0
	mfhi $t3
	beq $t3,$0,L1
	j L2
L1:
	addi $v0,$0,1
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	lw $t3,12($sp)
	addi $sp,$sp,16
	jr $ra
L2:
	addi $v0,$0,0
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	lw $t3,12($sp)
	addi $sp,$sp,16
	jr $ra


#ham get_ngay
Day:
	addi $sp,$sp,-12
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	addi $t1,$0,10
	lb $t0,0($a0)
	addi $t0,$t0,-48
	mult $t0,$t1
	mflo $t2
	lb $t0,1($a0)
	addi $t0,$t0,-48
	add $t2,$t2,$t0
	addi $v0,$t2,0
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	addi $sp,$sp,12
	jr $ra	

# Ham get_thang
Month:
	addi $sp,$sp,-12
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	addi $t1,$0,10
	lb $t0,3($a0)
	addi $t0,$t0,-48
	mult $t0,$t1
	mflo $t2
	lb $t0,4($a0)
	addi $t0,$t0,-48
	add $t2,$t2,$t0
	addi $v0,$t2,0
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	addi $sp,$sp,12
	jr $ra
	
# Ham get_nam
Year:
	addi $sp,$sp,-20
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	sw $t4,16($sp)
	add $v0,$v0,$0
	addi $t1,$0,1000
	addi $t3,$0,100
	addi $t4,$0,10
	lb $t0,6($a0)
	addi $t0,$t0,-48
	mult $t0,$t1
	mflo $t2
	addi $v0,$t2,0
	lb $t0,7($a0)
	addi $t0,$t0,-48
	mult $t0,$t3
	mflo $t2
	add $v0,$v0,$t2
	lb $t0,8($a0)
	addi $t0,$t0,-48
	mult $t0,$t4
	mflo $t2
	add $v0,$v0,$t2
	lb $t0,9($a0)
	addi $t0,$t0,-48
	add $v0,$v0,$t0
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	lw $t3,12($sp)
	lw $t4,16($sp)
	addi $sp,$sp,20
	jr $ra
	
#nam nhuan lien ke
namnhuanlienke:
	addi $sp,$sp,-16
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	addi $a0,$a0,1
	addi $t1,$0,0
Loop_namnhuanlienke:
	slti $t0,$t1,2 		#dem < 2
	beq $t0,$0,end_namnhuanlienke		#false	t0=0	
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal LeapYear	
	lw $ra,0($sp)
	addi $sp,$sp,4
	add $t3,$v0,$0
	addi $t2,$0,1
	bne $t2,$t3,ThemNam	#neu khong phai nam nhuan thi cong tiep va kiem tra
	add $t1,$t1,$t2		#tang bien dem=1
	addi $v0,$0,1		#xuat
	syscall
	add $a0,$a0,$t2		#va tang nam len
	add $a1,$a0,$0
	addi $v0,$0,11
	addi $a0,$0,32
	syscall
	add $a0,$a1,$0
	j Loop_namnhuanlienke
ThemNam:
	addi $a0,$a0,1
	j Loop_namnhuanlienke
end_namnhuanlienke:
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	lw $t3,12($sp)
	addi $sp,$sp,16
	jr $ra
	
#Ham chuyen Dinh Dang
Convert:
addi $sp,$sp,-40
sw $t0,0($sp)
sw $t1,4($sp)
sw $t2,8($sp)
sw $t3,12($sp)
sw $t4,16($sp)
sw $t5,20($sp)
sw $s0,24($sp)
sw $s1,28($sp)
sw $s2,32($sp)
sw $s4,36($sp)
addi $s0,$0,0 #s0,s1,s2 lan luot giu so ki tu cua ngay thang nam
addi $s1,$0,0
addi $s2,$0,0
addi $t2,$0,47 # t2 giu dau /
addi $t4,$a0,0 #cho t4 giu dia chi chuoi time
Loop1: #luu chuoi ngay
lb $t0,0($a0) #t0 giu gia tri ki tu lay ra 
beq $t0,$t2,Loop2 # neu ki tu la / thi co nghia la xong chuoi ngay 
addi $sp,$sp,-1
sb $t0,0($sp) #luu t0 vao stack
addi $a0,$a0,1 #sang ki tu tiep theo cua chuoi	
addi $s0,$s0,1
j Loop1
Loop2:#luu chuoi thang
addi $a0,$a0,1
lb $t0,0($a0) #t0 giu gia tri ki tu lay ra 
beq $t0,$t2,Loop3 #neu ki tu la / thi xong chuoi thang chuyen 3 chuoi nam
addi $sp,$sp,-1
sb $t0,0($sp) #luu t0 vao stack
addi $s1,$s1,1
j Loop2
Loop3:
addi $a0,$a0,1
lb $t0,0($a0) #t0 giu gia tri ki tu lay ra 
slti $t3, $t0, 48			
bne $t3, $0, convert_endstore	
slti $t3, $t0, 58			
beq $t3, $0, convert_endstore
addi $sp,$sp,-1
sb $t0,0($sp) #luu t0 vao stack
addi $s2,$s2,1
j Loop3
convert_endstore :
addi $a0,$t4,0 #cho A0 giu dia chi chuoi time
addi $t3,$0,65
beq $a1,$t3,DD1
addi $t3,$0,66
beq $a1,$t3,DD2
DD3:
addi $t2,$0,32 #t2 giu ki tu khoang cach
addi $t5,$0,44 #t5 giu ki tu ,
#Ngay
addi $sp,$sp,-1
add $sp,$sp,$s2 
add $sp,$sp,$s1
add $sp,$sp,$s0 # dua sp ve cho de lay gia tri ngay ra
addi $s4,$s0,0 #s4 giu so ki tu cua thang,ngay,nam 

LoopNgayDD3:
beq $s4,$0,LoopThang1DD3
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopNgayDD3

LoopThang1DD3:
sb $t2,0($a0)#them dau khoang trong
addi $a0,$a0,1
addi $s4,$s1,0

LoopThang2DD3:
beq $s4,$0,LoopNam1DD3
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopThang2DD3

LoopNam1DD3 :
sb $t5,0($a0)#them dau ,
addi $a0,$a0,1
sb $t2,0($a0)#them dau khoang trong
addi $a0,$a0,1
addi $s4,$s2,0

LoopNam2DD3:
beq $s4,$0,EndLoopNamDD3
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopNam2DD3

EndLoopNamDD3 :
addi $v0,$t4,0
addi $sp,$sp,1
add $sp,$sp,$s0
add $sp,$sp,$s1
add $sp,$sp,$s2
lw $t0,0($sp)
lw $t1,4($sp)
lw $t2,8($sp)
lw $t3,12($sp)
lw $t4,16($sp)
lw $t5,20($sp)
lw $s0,24($sp)
lw $s1,28($sp)
lw $s2,32($sp)
lw $s4,36($sp)
addi $sp,$sp,40
jr $ra
DD2 :
addi $t2,$0,32 #t2 giu ki tu khoang cach
addi $t5,$0,44 #t5 giu ki tu ,
#Thang
addi $sp,$sp,-1
add $sp,$sp,$s2 
add $sp,$sp,$s1 # dua sp ve cho de lay gia tri thang ra
addi $s4,$s1,0 #s4 giu so ki tu cua thang,ngay,nam 

LoopThangDD2 :
beq $s4,$0,LoopNgay1DD2
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopThangDD2
#Ngay
LoopNgay1DD2 :
sb $t2,0($a0)#them dau khoang trong
addi $a0,$a0,1
add $sp,$sp,$s1
add $sp,$sp,$s0#dua sp ve cho de lay gia tri ngay
addi $s4,$s0,0
LoopNgay2DD2 :
beq $s4,$0,LoopNam1DD2
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopNgay2DD2

LoopNam1DD2 :
sb $t5,0($a0)#them dau ,
addi $a0,$a0,1
sb $t2,0($a0)#them dau khoang trong
addi $a0,$a0,1
sub $sp,$sp,$s1#dua sp ve cho de lay gia tri nam
addi $s4,$s2,0

LoopNam2DD2 :
beq $s4,$0,EndLoopNamDD2
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopNam2DD2

EndLoopNamDD2 :
addi $v0,$t4,0
addi $sp,$sp,1
add $sp,$sp,$s0
add $sp,$sp,$s1
add $sp,$sp,$s2
lw $t0,0($sp)
lw $t1,4($sp)
lw $t2,8($sp)
lw $t3,12($sp)
lw $t4,16($sp)
lw $t5,20($sp)
lw $s0,24($sp)
lw $s1,28($sp)
lw $s2,32($sp)
lw $s4,36($sp)
addi $sp,$sp,40
jr $ra
DD1 :
#Thang
addi $sp,$sp,-1
add $sp,$sp,$s2 
add $sp,$sp,$s1 # dua sp ve cho de lay gia tri thang ra
addi $s4,$s1,0 #s4 giu so ki tu cua thang,ngay,nam 

LoopThang :
beq $s4,$0,LoopNgay1
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopThang
#Ngay
LoopNgay1 :
sb $t2,0($a0)#them dau /
addi $a0,$a0,1
add $sp,$sp,$s1
add $sp,$sp,$s0#dua sp ve cho de lay gia tri ngay
addi $s4,$s0,0

LoopNgay2 :
beq $s4,$0,LoopNam1
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopNgay2

LoopNam1 :
sb $t2,0($a0)#them dau /
addi $a0,$a0,1
sub $sp,$sp,$s1#dua sp ve cho de lay gia tri nam
addi $s4,$s2,0
LoopNam2 :
beq $s4,$0,EndLoopNam
lb $t0,0($sp)
sb $t0,0($a0)
addi $a0,$a0,1
addi $sp,$sp,-1
addi $s4,$s4,-1
j LoopNam2

EndLoopNam :
addi $v0,$t4,0
addi $sp,$sp,1
add $sp,$sp,$s0
add $sp,$sp,$s1
add $sp,$sp,$s2
lw $t0,0($sp)
lw $t1,4($sp)
lw $t2,8($sp)
lw $t3,12($sp)
lw $t4,16($sp)
lw $t5,20($sp)
lw $s0,24($sp)
lw $s1,28($sp)
lw $s2,32($sp)
lw $s4,36($sp)
addi $sp,$sp,40
jr $ra

#
KhoangCach:
	addi $sp,$sp,-20
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	sw $t4,16($sp)
	addi $t3,$a0,0		#luu chuoi Time 1
	addi $t4,$a1,0		#luu chuoi Time 2
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal Year
	addi $t0,$v0,0
	addi $a0,$a1,0
	jal Year
	lw $ra,0($sp)
	addi $sp,$sp,4
	addi $t1,$v0,0
	beq $t0,$t1,TT2		#so sanh $t0 = $t1
	slt $t2,$t0,$t1		#so sanh $t0 < $t1 hay khong
	beq $t2,$0,TT3		#TH $t0 > $t1
	j TT1			#$t0 < $t1
TT1:
	addi $a0,$t3,0		#chuoi co nam nho hon vao a0
	addi $a1,$t4,0		#chuoi co nam lon hon vao a1
	j Truyen
TT2:	#TH Year 1 = Year 2 thi KQ = 0
	addi $v0,$0,0
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	lw $t3,12($sp)
	lw $t4,16($sp)
	addi $sp,$sp,20
	jr $ra
TT3:
	addi $a0,$t4,0		#chuoi co nam nho hon vao a0
	addi $a1,$t3,0		#chuoi co nam lon hon vao a1
	j Truyen
Truyen:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal TinhKhoangCach
	lw $ra,0($sp)
	addi $sp,$sp,4
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	lw $t3,12($sp)
	lw $t4,16($sp)
	addi $sp,$sp,20
	jr $ra
	
# Ham tinh khoang cach giu 2 Time
TinhKhoangCach:
	addi $sp,$sp,-24
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	sw $a0,16($sp)
	sw $ra,20($sp)
	jal Year
	addi $t0,$v0,0		#t0 giu nam nho hon
	addi $a0,$a1,0
	jal Year
	addi $t1,$v0,0		#t1 giu nam lon hon
	sub $t2,$t1,$t0		#$t2 giu kc nam.
	lw $a0,16($sp)
	jal Month
	addi $t0,$v0,0		#t0 giu thang cua nam nho hon
	addi $a0,$a1,0
	jal Month
	addi $t1,$v0,0		#t1 giu thang cua nam lon hon
	beq $t0,$t1,SSNgay
	slt $t3,$t0,$t1		#so sanh t1 > t0 hay khong
	bne $t3,$0,KQ1
	j KQ2
KQ1:
	addi $v0,$t2,0
	j End_KC	
KQ2:
	addi $v0,$t2,-1
	j End_KC
SSNgay:
	lw $a0,16($sp)
	jal Day
	addi $t0,$v0,0		#t0 giu ngay cua nam nho hon
	addi $a0,$a1,0
	jal Day
	addi $t1,$v0,0		#t1 giu ngay cua nam lon hon
	slt $t3,$t1,$t0		#t0 < t1 hay khong
	beq $t3,$0,KQ1
	j KQ2
	
End_KC:
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	lw $t3,12($sp)
	lw $a0,16($sp)
	lw $ra,20($sp)
	addi $sp,$sp,24
	jr $ra

#Kiem Tra Ki Tu
KiemTraKiTu:
addi $sp,$sp,-16
sw $t0,0($sp)
sw $t1,4($sp)
sw $t2,8($sp)
sw $t3,12($sp)
addi $t1,$0,10  #cho t1 giu gia tri xuong dong 
addi $t2,$0,3 #t2 giu so lan kiem tra
lb $t0,0($a0)
beq $t0,$t1,end2	#kiem tra ngay = rong
lb $t0,0($a1)
beq $t0,$t1,end2	#kiem tra thang = rong
lb $t0,0($a2)
beq $t0,$t1,end2	#kiem tra nam = rong
loopKiemTraKiTu:
lb $t0,0($a0)
beq $t0,$t1,end1 #dung
slti $t3, $t0, 48	# if (c < 48)
bne $t3, $0, end2	#sai
slti $t3, $t0, 58	# if (c >= 58)
beq $t3, $0, end2	#sai
addi $a0,$a0,1
j loopKiemTraKiTu

end1:
addi $t2,$t2,-1 #giam so lan kiem tra xuong
beq $t2,$0,endKiemTraKiTu
addi $a0,$a1,0 #sau khi kiem tra ngay dung thi se kiem tra thang
addi $a1,$a2,0 #cho a1 giu chuoi nam de sau khi kiem tra thang dung thi kiem tra nam
j loopKiemTraKiTu

end2:
addi $v0,$0,0
lw $t0,0($sp)
lw $t1,4($sp)
lw $t2,8($sp)
lw $t3,12($sp)
addi $sp,$sp,16
jr $ra

endKiemTraKiTu:
addi $v0,$0,1
lw $t0,0($sp)
lw $t1,4($sp)
lw $t2,8($sp)
lw $t3,12($sp)
addi $sp,$sp,16
jr $ra


#Kiem tra so
KiemTraSo:
	#Cat cac thanh ghi $t
	addi $sp,$sp,-8
	sw $t0,0($sp)
	sw $t1,4($sp)
	slti $t0,$a1,13
	beq $t0,$0,KiemTraSo2
	addi $t0,$0,2
	beq $a1,$t0,KT_LeapYear		#thang = 2
	addi $t0,$t0,2
	beq $a1,$t0,Month_30		#thang = 4
	addi $t0,$t0,2
	beq $a1,$t0,Month_30		#thang = 6
	addi $t0,$t0,3
	beq $a1,$t0,Month_30		#thang = 9
	addi $t0,$t0,2
	beq $a1,$t0,Month_30		#thang = 11
	j Month_31
Month_30:	#nhung thang co 30 ngay
	slti $t1,$a0,31
	beq $t1,$0,KiemTraSo2
	j KiemTraSo1
Month_31: #nhung thang co 31 ngay
	slti $t1,$a0,32
	beq $t1,$0,KiemTraSo2
	j KiemTraSo1
KT_LeapYear:	#thang 2
	addi $sp,$sp,-4		
	sw $a0,0($sp)		#luu chuoi Time vao stacks
	addi $a0,$a2,0
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal LeapYear
	lw $ra,0($sp)
	addi $sp,$sp,4
	lw $a0,0($sp)		#Lay chuoi Time ra khoi stacks
	addi $sp,$sp,4
	beq $v0,$0,Month_28
	j Month_29	
	
Month_28:
	slti $t1,$a0,29
	beq $t1,$0,KiemTraSo2
	j KiemTraSo1
Month_29:	
	slti $t1,$a0,30
	beq $t1,$0,KiemTraSo2
	j KiemTraSo1
KiemTraSo1:
	addi $v0,$0,1
	lw $t0,0($sp)
	lw $t1,4($sp)
	addi $sp,$sp,8
	jr $ra
KiemTraSo2:
	addi $v0,$0,0
	lw $t0,0($sp)
	lw $t1,4($sp)
	addi $sp,$sp,8
	jr $ra
	
NhapLai:
	la $a0,nhaplai
	addi $v0,$0,4
	syscall
	j Nhap


#thu trong tuan		#d + m + y + y/4 + c
weekday:
	#Cat $t
	addi $sp,$sp,-20
	sw $t0,0($sp)
	sw $t1,4($sp)
	sw $t2,8($sp)
	sw $t3,12($sp)
	sw $t4,12($sp)
	#
	addi $s0,$0,0		#sum
	add $s0,$a0,$0		#s0 = ngay
	addi $t0,$0,100		#100
	#the ky
	div $a2,$t0
	mfhi $t1		#so du = y
	add $s0,$s0,$t1
	mflo $t2 		#thuong = c (the ky) 
	beq $t1,$0,KT_TKtron		#neu chia het thi tiep tuc
	j KT_TKdu
KT_TKtron:
	add $s0,$s0,$t2		#sum = d + c + y
	j res
KT_TKdu:
	addi $t2,$t2,1
	add $s0,$s0,$t2		#sum = d + c + y
	j res
res:
	addi $t0,$0,4
	div $t1,$t0
	mflo $t3	# t3 = y/4
	add $s0,$s0,$t3
TinhTong:
#Xet thang = ?
	addi $t0,$0,1		
	beq $a1,$t0,Th1
	addi $t0,$t0,1
	beq $a1,$t0,Th2
	addi $t0,$t0,1		
	beq $a1,$t0,Th3
	addi $t0,$t0,1		
	beq $a1,$t0,Th4
	addi $t0,$t0,1		
	beq $a1,$t0,Th5
	addi $t0,$t0,1		
	beq $a1,$t0,Th6
	addi $t0,$t0,1		
	beq $a1,$t0,Th4
	addi $t0,$t0,1		
	beq $a1,$t0,Th8
	addi $t0,$t0,1		
	beq $a1,$t0,Th12
	addi $t0,$t0,1		
	beq $a1,$t0,Th10
	addi $t0,$t0,1		
	beq $a1,$t0,Th3
Th12:	
	addi $s0,$s0,5
	j trave
Th1:
	add $a0,$a2,$0
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal LeapYear
	lw $ra,0($sp)
	addi $sp,$sp,4
	beq $v0,$0,Th10
	addi $s0,$s0,6
	j trave
Th2:
	add $a0,$a2,$0
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal LeapYear
	lw $ra,0($sp)
	addi $sp,$sp,4
	beq $v0,$0,Th3
	addi $s0,$s0,2
	j trave
Th3:	
	addi $s0,$s0,3
	j trave
Th4:
	addi $s0,$s0,6
	j trave
Th5:
	addi $s0,$s0,1
	j trave
Th6:
	addi $s0,$s0,4
	j trave
Th8:
	addi $s0,$s0,2
	j trave
Th10:
	addi $s0,$s0,0
	j trave
trave:	#sum = s0
	addi $t4,$0,7
	div $s0,$t4
	mfhi $v0
	lw $t0,0($sp)
	lw $t1,4($sp)
	lw $t2,8($sp)
	lw $t3,12($sp)
	lw $t4,12($sp)
	addi $sp,$sp,20
	jr $ra
