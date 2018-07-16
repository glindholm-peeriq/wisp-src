/* 
	Copyright (c) 1995 DevTech Migrations, All rights reserved.
	$Id:$
*/
/* WANG_DECIMALS.H ...	This is a special include file used when interfacing with routines designed to be called by WISP'd,	*/
/*			WANG programs.  These WANG programs store their numerical values in reverse order.  We have to do	*/
/*			the same here.  In binary representation, 65536 is 00000000 00000001 00000000 00000000, yielding	*/
/* 			a 4 byte integer, which when swapped, will be equal to 1, 00000000 00000000 00000000 00000001.		*/

/*			For UNIX it is a straight thru operation.								*/

#ifdef VMS
#define wang_dec_0  0
#define wang_dec_1  65536                                                       
#define wang_dec_2  131072                                                      
#define wang_dec_3  196608                                                      
#define wang_dec_4  262144                                                      
#define wang_dec_5  327680                                                      
#define wang_dec_6  393216                                                      
#define wang_dec_7  458752                                                      
#define wang_dec_8  524288                                                      
#define wang_dec_9  589824                                                      
#define wang_dec_10  655360                                                     
#define wang_dec_11  720896                                                     
#define wang_dec_12  786432                                                     
#define wang_dec_13  851968                                                     
#define wang_dec_14  917504                                                     
#define wang_dec_15  983040                                                     
#define wang_dec_16  1048576                                                    
#define wang_dec_17  1114112                                                    
#define wang_dec_18  1179648                                                    
#define wang_dec_19  1245184                                                    
#define wang_dec_20  1310720                                                    
#define wang_dec_21  1376256                                                    
#define wang_dec_22  1441792                                                    
#define wang_dec_23  1507328                                                    
#define wang_dec_24  1572864                                                    
#define wang_dec_25  1638400                                                    
#define wang_dec_26  1703936                                                    
#define wang_dec_27  1769472                                                    
#define wang_dec_28  1835008                                                    
#define wang_dec_29  1900544                                                    
#define wang_dec_30  1966080                                                    
#define wang_dec_31  2031616                                                    
#define wang_dec_32  2097152                                                    
#define wang_dec_33  2162688                                                    
#define wang_dec_34  2228224                                                    
#define wang_dec_35  2293760                                                    
#define wang_dec_36  2359296                                                    
#define wang_dec_37  2424832                                                    
#define wang_dec_38  2490368                                                    
#define wang_dec_39  2555904                                                    
#define wang_dec_40  2621440                                                    
#define wang_dec_41  2686976                                                    
#define wang_dec_42  2752512                                                    
#define wang_dec_43  2818048                                                    
#define wang_dec_44  2883584                                                    
#define wang_dec_45  2949120                                                    
#define wang_dec_46  3014656                                                    
#define wang_dec_47  3080192                                                    
#define wang_dec_48  3145728                                                    
#define wang_dec_49  3211264                                                    
#define wang_dec_50  3276800                                                    
#define wang_dec_51  3342336                                                    
#define wang_dec_52  3407872                                                    
#define wang_dec_53  3473408                                                    
#define wang_dec_54  3538944                                                    
#define wang_dec_55  3604480                                                    
#define wang_dec_56  3670016                                                    
#define wang_dec_57  3735552                                                    
#define wang_dec_58  3801088                                                    
#define wang_dec_59  3866624                                                    
#define wang_dec_60  3932160                                                    
#define wang_dec_61  3997696                                                    
#define wang_dec_62  4063232                                                    
#define wang_dec_63  4128768                                                    
#define wang_dec_64  4194304                                                    
#define wang_dec_65  4259840                                                    
#define wang_dec_66  4325376                                                    
#define wang_dec_67  4390912                                                    
#define wang_dec_68  4456448                                                    
#define wang_dec_69  4521984                                                    
#define wang_dec_70  4587520                                                    
#define wang_dec_71  4653056                                                    
#define wang_dec_72  4718592                                                    
#define wang_dec_73  4784128                                                    
#define wang_dec_74  4849664                                                    
#define wang_dec_75  4915200                                                    
#define wang_dec_76  4980736                                                    
#define wang_dec_77  5046272                                                    
#define wang_dec_78  5111808                                                    
#define wang_dec_79  5177344                                                    
#define wang_dec_80  5242880                                                    
#define wang_dec_81  5308416                                                    
#define wang_dec_82  5373952                                                    
#define wang_dec_83  5439488                                                    
#define wang_dec_84  5505024                                                    
#define wang_dec_85  5570560                                                    
#define wang_dec_86  5636096                                                    
#define wang_dec_87  5701632                                                    
#define wang_dec_88  5767168                                                    
#define wang_dec_89  5832704                                                    
#define wang_dec_90  5898240                                                    
#define wang_dec_91  5963776                                                    
#define wang_dec_92  6029312                                                    
#define wang_dec_93  6094848                                                    
#define wang_dec_94  6160384                                                    
#define wang_dec_95  6225920                                                    
#define wang_dec_96  6291456                                                    
#define wang_dec_97  6356992                                                    
#define wang_dec_98  6422528                                                    
#define wang_dec_99  6488064                                                    
#define wang_dec_100  6553600                                                   
#endif
#ifdef unix
#define wang_dec_0  	0
#define wang_dec_1  	1
#define wang_dec_2  	2
#define wang_dec_3  	3
#define wang_dec_4  	4
#define wang_dec_5  	5
#define wang_dec_6  	6
#define wang_dec_7  	7
#define wang_dec_8  	8
#define wang_dec_9  	9
#define wang_dec_10 	10
#define wang_dec_11  	11
#define wang_dec_12  	12
#define wang_dec_13  	13
#define wang_dec_14  	14
#define wang_dec_15  	15
#define wang_dec_16  	16
#define wang_dec_17  	17
#define wang_dec_18  	18
#define wang_dec_19  	19
#define wang_dec_20  	20
#define wang_dec_21  	21
#define wang_dec_22  	22
#define wang_dec_23  	23
#define wang_dec_24  	24
#define wang_dec_25  	25
#define wang_dec_26  	26
#define wang_dec_27  	27
#define wang_dec_28  	28
#define wang_dec_29  	29
#define wang_dec_30  	30
#define wang_dec_31  	31
#define wang_dec_32  	32
#define wang_dec_33  	33
#define wang_dec_34  	34
#define wang_dec_35  	35
#define wang_dec_36  	36
#define wang_dec_37  	37
#define wang_dec_38  	38
#define wang_dec_39  	39
#define wang_dec_40  	40
#define wang_dec_41  	41
#define wang_dec_42  	42
#define wang_dec_43  	43
#define wang_dec_44  	44
#define wang_dec_45  	45
#define wang_dec_46  	46
#define wang_dec_47  	47
#define wang_dec_48  	48
#define wang_dec_49  	49
#define wang_dec_50  	50
#define wang_dec_51  	51
#define wang_dec_52  	52
#define wang_dec_53  	53
#define wang_dec_54  	54
#define wang_dec_55  	55
#define wang_dec_56  	56
#define wang_dec_57  	57
#define wang_dec_58  	58
#define wang_dec_59  	59
#define wang_dec_60  	60
#define wang_dec_61  	61
#define wang_dec_62  	62
#define wang_dec_63  	63	
#define wang_dec_64  	64
#define wang_dec_65  	65	
#define wang_dec_66  	66
#define wang_dec_67  	67
#define wang_dec_68  	68
#define wang_dec_69  	69
#define wang_dec_70  	70
#define wang_dec_71  	71
#define wang_dec_72  	72
#define wang_dec_73  	73
#define wang_dec_74  	74
#define wang_dec_75  	75
#define wang_dec_76  	76
#define wang_dec_77  	77
#define wang_dec_78  	78
#define wang_dec_79  	79
#define wang_dec_80  	80
#define wang_dec_81  	81
#define wang_dec_82  	82
#define wang_dec_83  	83
#define wang_dec_84  	84
#define wang_dec_85  	85
#define wang_dec_86  	86
#define wang_dec_87  	87
#define wang_dec_88  	88
#define wang_dec_89  	89
#define wang_dec_90  	90
#define wang_dec_91  	91
#define wang_dec_92  	92
#define wang_dec_93  	93
#define wang_dec_94  	94
#define wang_dec_95  	95
#define wang_dec_96  	96
#define wang_dec_97  	97	
#define wang_dec_98  	98
#define wang_dec_99  	99
#define wang_dec_100	100 
#endif
/*
**	History:
**	$Log: wngdcmls.h,v $
**	Revision 1.8  1996/08/19 22:33:19  gsl
**	drcs update
**	
**
**
*/
