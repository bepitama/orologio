EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5EB808A2
P 4850 2850
F 0 "A1" H 4850 1761 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 4850 1670 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 4850 2850 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4850 2850 50  0001 C CNN
	1    4850 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5EB81EC7
P 6500 3100
F 0 "R1" H 6570 3146 50  0000 L CNN
F 1 "100K" H 6570 3055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6430 3100 50  0001 C CNN
F 3 "~" H 6500 3100 50  0001 C CNN
	1    6500 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2850 6500 2850
Wire Wire Line
	6500 2850 6500 2950
Wire Wire Line
	4850 3850 4850 4100
Wire Wire Line
	4850 4100 5500 4100
Wire Wire Line
	6500 4100 6500 3400
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5EB835F3
P 6700 2500
F 0 "J2" H 6780 2492 50  0000 L CNN
F 1 "Photoresistor" H 6780 2401 50  0000 L CNN
F 2 "Connector_JST:JST_EH_B2B-EH-A_1x02_P2.50mm_Vertical" H 6700 2500 50  0001 C CNN
F 3 "~" H 6700 2500 50  0001 C CNN
	1    6700 2500
	1    0    0    1   
$EndComp
Wire Wire Line
	6500 2850 6500 2500
Connection ~ 6500 2850
Wire Wire Line
	6500 1300 6400 1300
Wire Wire Line
	5050 1300 5050 1850
Wire Wire Line
	6000 3400 5850 3400
Wire Wire Line
	5850 3400 5850 1300
Connection ~ 5850 1300
Wire Wire Line
	5850 1300 5600 1300
Wire Wire Line
	6000 3500 5850 3500
Wire Wire Line
	5850 3500 5850 4100
Connection ~ 5850 4100
Wire Wire Line
	5850 4100 5950 4100
Wire Wire Line
	6000 3600 5650 3600
Wire Wire Line
	5650 3600 5650 3350
Wire Wire Line
	5650 3350 5350 3350
Wire Wire Line
	6000 3700 5750 3700
Wire Wire Line
	5750 3700 5750 3250
Wire Wire Line
	5750 3250 5350 3250
$Comp
L Transistor_BJT:2N2219 Q4
U 1 1 5EB8CC9F
P 3050 2850
F 0 "Q4" H 3241 2896 50  0000 L CNN
F 1 "2N2219" H 3241 2805 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92" H 3250 2775 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/2N2219-D.PDF" H 3050 2850 50  0001 L CNN
	1    3050 2850
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5EB902C0
P 3700 2850
F 0 "R5" V 3493 2850 50  0000 C CNN
F 1 "1000" V 3584 2850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3630 2850 50  0001 C CNN
F 3 "~" H 3700 2850 50  0001 C CNN
	1    3700 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	3550 2850 3250 2850
Wire Wire Line
	2950 4100 2950 3050
Connection ~ 4850 4100
$Comp
L Device:R R6
U 1 1 5EB91A42
P 3700 3100
F 0 "R6" V 3493 3100 50  0000 C CNN
F 1 "1000" V 3584 3100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3630 3100 50  0001 C CNN
F 3 "~" H 3700 3100 50  0001 C CNN
	1    3700 3100
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 5EB91E4B
P 3700 3350
F 0 "R7" V 3493 3350 50  0000 C CNN
F 1 "1000" V 3584 3350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3630 3350 50  0001 C CNN
F 3 "~" H 3700 3350 50  0001 C CNN
	1    3700 3350
	0    1    1    0   
$EndComp
$Comp
L Device:R R8
U 1 1 5EB9216C
P 3700 3650
F 0 "R8" V 3493 3650 50  0000 C CNN
F 1 "1000" V 3584 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3630 3650 50  0001 C CNN
F 3 "~" H 3700 3650 50  0001 C CNN
	1    3700 3650
	0    1    1    0   
$EndComp
$Comp
L Transistor_BJT:2N2219 Q3
U 1 1 5EB95606
P 2650 3100
F 0 "Q3" H 2841 3146 50  0000 L CNN
F 1 "2N2219" H 2841 3055 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92" H 2850 3025 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/2N2219-D.PDF" H 2650 3100 50  0001 L CNN
	1    2650 3100
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N2219 Q2
U 1 1 5EB95FE3
P 2250 3350
F 0 "Q2" H 2441 3396 50  0000 L CNN
F 1 "2N2219" H 2441 3305 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92" H 2450 3275 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/2N2219-D.PDF" H 2250 3350 50  0001 L CNN
	1    2250 3350
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N2219 Q1
U 1 1 5EB965D9
P 1900 3650
F 0 "Q1" H 2091 3696 50  0000 L CNN
F 1 "2N2219" H 2091 3605 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92" H 2100 3575 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/2N2219-D.PDF" H 1900 3650 50  0001 L CNN
	1    1900 3650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3550 3100 2850 3100
Wire Wire Line
	3550 3350 2450 3350
Wire Wire Line
	3550 3650 2100 3650
Wire Wire Line
	1800 3850 1800 4100
Wire Wire Line
	1800 4100 2150 4100
Connection ~ 2950 4100
Wire Wire Line
	2550 3300 2550 4100
Connection ~ 2550 4100
Wire Wire Line
	2550 4100 2800 4100
Wire Wire Line
	2150 3550 2150 4100
Connection ~ 2150 4100
Wire Wire Line
	2150 4100 2550 4100
$Comp
L Device:R R4
U 1 1 5EB9FDE0
P 3500 1950
F 0 "R4" H 3570 1996 50  0000 L CNN
F 1 "10K" H 3570 1905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3430 1950 50  0001 C CNN
F 3 "~" H 3500 1950 50  0001 C CNN
	1    3500 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5EBA0669
P 3150 1950
F 0 "R3" H 3220 1996 50  0000 L CNN
F 1 "10K" H 3220 1905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3080 1950 50  0001 C CNN
F 3 "~" H 3150 1950 50  0001 C CNN
	1    3150 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5EBA094D
P 2800 1950
F 0 "R2" H 2870 1996 50  0000 L CNN
F 1 "10K" H 2870 1905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2730 1950 50  0001 C CNN
F 3 "~" H 2800 1950 50  0001 C CNN
	1    2800 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 1300 4100 1300
Wire Wire Line
	3600 1300 3600 1150
Connection ~ 5050 1300
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 5EBA3D55
P 2800 950
F 0 "J7" V 3050 950 50  0000 R CNN
F 1 "BUT3" V 2950 1000 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2800 950 50  0001 C CNN
F 3 "~" H 2800 950 50  0001 C CNN
	1    2800 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3250 1150 3250 1300
Wire Wire Line
	3250 1300 3600 1300
Connection ~ 3600 1300
Wire Wire Line
	2900 1150 2900 1300
Wire Wire Line
	2900 1300 3250 1300
Connection ~ 3250 1300
Wire Wire Line
	3500 1150 3500 1750
Wire Wire Line
	3150 1150 3150 1750
Wire Wire Line
	2800 1150 2800 1750
Wire Wire Line
	2800 2100 2800 4100
Connection ~ 2800 4100
Wire Wire Line
	2800 4100 2950 4100
Wire Wire Line
	3150 2100 3150 4100
Wire Wire Line
	2950 4100 3150 4100
Connection ~ 3150 4100
Wire Wire Line
	3150 4100 3500 4100
Wire Wire Line
	3500 2100 3500 4100
Connection ~ 3500 4100
Wire Wire Line
	3500 4100 3900 4100
Wire Wire Line
	4350 2850 3850 2850
Wire Wire Line
	3850 3100 4050 3100
Wire Wire Line
	4050 3100 4050 3150
Wire Wire Line
	4050 3150 4350 3150
Wire Wire Line
	4350 3250 4050 3250
Wire Wire Line
	4050 3250 4050 3350
Wire Wire Line
	4050 3350 3850 3350
Wire Wire Line
	3850 3650 4100 3650
Wire Wire Line
	4100 3650 4100 3350
Wire Wire Line
	4100 3350 4350 3350
$Comp
L Connector_Generic:Conn_01x03 J10
U 1 1 5EBDFA47
P 4000 950
F 0 "J10" V 4250 1000 50  0000 R CNN
F 1 "WS2812" V 4150 1100 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4000 950 50  0001 C CNN
F 3 "~" H 4000 950 50  0001 C CNN
	1    4000 950 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J8
U 1 1 5EBE37FD
P 3150 950
F 0 "J8" V 3400 950 50  0000 R CNN
F 1 "BUT2" V 3300 1000 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3150 950 50  0001 C CNN
F 3 "~" H 3150 950 50  0001 C CNN
	1    3150 950 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J9
U 1 1 5EBE3D65
P 3500 950
F 0 "J9" V 3750 950 50  0000 R CNN
F 1 "BUT1" V 3650 1000 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3500 950 50  0001 C CNN
F 3 "~" H 3500 950 50  0001 C CNN
	1    3500 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3800 2550 3800 1750
Wire Wire Line
	3800 1750 3500 1750
Connection ~ 3500 1750
Wire Wire Line
	3500 1750 3500 1800
Wire Wire Line
	3800 2550 4350 2550
Wire Wire Line
	4350 2650 3300 2650
Wire Wire Line
	3300 2650 3300 1750
Wire Wire Line
	3300 1750 3150 1750
Connection ~ 3150 1750
Wire Wire Line
	3150 1750 3150 1800
Wire Wire Line
	4350 2750 3200 2750
Wire Wire Line
	3200 2750 3200 2150
Wire Wire Line
	3200 2150 2950 2150
Wire Wire Line
	2950 2150 2950 1750
Wire Wire Line
	2950 1750 2800 1750
Connection ~ 2800 1750
Wire Wire Line
	2800 1750 2800 1800
$Comp
L Connector_Generic:Conn_01x02 J6
U 1 1 5EBF32CA
P 2400 950
F 0 "J6" V 2650 950 50  0000 R CNN
F 1 "LED1" V 2550 1000 50  0000 R CNN
F 2 "Connector_JST:JST_EH_B2B-EH-A_1x02_P2.50mm_Vertical" H 2400 950 50  0001 C CNN
F 3 "~" H 2400 950 50  0001 C CNN
	1    2400 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2900 1300 2500 1300
Wire Wire Line
	2500 1300 2500 1150
Connection ~ 2900 1300
Wire Wire Line
	2950 2650 2950 2350
Wire Wire Line
	2950 2350 2400 2350
Wire Wire Line
	2400 2350 2400 1150
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 5EBF79B9
P 2000 950
F 0 "J5" V 2250 950 50  0000 R CNN
F 1 "LED2" V 2150 1000 50  0000 R CNN
F 2 "Connector_JST:JST_EH_B2B-EH-A_1x02_P2.50mm_Vertical" H 2000 950 50  0001 C CNN
F 3 "~" H 2000 950 50  0001 C CNN
	1    2000 950 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5EBF7FB9
P 1600 950
F 0 "J4" V 1850 950 50  0000 R CNN
F 1 "LED3" V 1750 1000 50  0000 R CNN
F 2 "Connector_JST:JST_EH_B2B-EH-A_1x02_P2.50mm_Vertical" H 1600 950 50  0001 C CNN
F 3 "~" H 1600 950 50  0001 C CNN
	1    1600 950 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5EBF872E
P 1200 950
F 0 "J3" V 1450 950 50  0000 R CNN
F 1 "LED4" V 1350 1000 50  0000 R CNN
F 2 "Connector_JST:JST_EH_B2B-EH-A_1x02_P2.50mm_Vertical" H 1200 950 50  0001 C CNN
F 3 "~" H 1200 950 50  0001 C CNN
	1    1200 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2500 1300 2100 1300
Wire Wire Line
	2100 1300 2100 1150
Connection ~ 2500 1300
Wire Wire Line
	2100 1300 1700 1300
Wire Wire Line
	1700 1300 1700 1150
Connection ~ 2100 1300
Wire Wire Line
	1700 1300 1300 1300
Wire Wire Line
	1300 1300 1300 1150
Connection ~ 1700 1300
Wire Wire Line
	2550 2900 2550 2450
Wire Wire Line
	2550 2450 2000 2450
Wire Wire Line
	2000 2450 2000 1150
Wire Wire Line
	2150 3150 2150 2550
Wire Wire Line
	2150 2550 1600 2550
Wire Wire Line
	1600 2550 1600 1150
Wire Wire Line
	1800 3450 1800 2650
Wire Wire Line
	1800 2650 1200 2650
Wire Wire Line
	1200 2650 1200 1150
Wire Wire Line
	4100 1150 4100 1300
Connection ~ 4100 1300
Wire Wire Line
	4100 1300 3600 1300
Wire Wire Line
	3900 1150 3900 4100
Connection ~ 3900 4100
Wire Wire Line
	3900 4100 4850 4100
Wire Wire Line
	4350 3050 4000 3050
Wire Wire Line
	4000 3050 4000 1150
$Comp
L Connector_Generic:Conn_01x02 J11
U 1 1 5EC1DC7C
P 5500 950
F 0 "J11" V 5464 762 50  0000 R CNN
F 1 "Power" V 5373 762 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5500 950 50  0001 C CNN
F 3 "~" H 5500 950 50  0001 C CNN
	1    5500 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5500 1150 5500 4100
Connection ~ 5500 4100
Wire Wire Line
	5500 4100 5850 4100
Wire Wire Line
	5600 1150 5600 1300
Connection ~ 5600 1300
Wire Wire Line
	5600 1300 5050 1300
$Comp
L Device:R_POT RV1
U 1 1 5EC27AD2
P 5950 3050
F 0 "RV1" H 5880 3096 50  0000 R CNN
F 1 "R_POT" H 5880 3005 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_ACP_CA9-V10_Vertical" H 5950 3050 50  0001 C CNN
F 3 "~" H 5950 3050 50  0001 C CNN
	1    5950 3050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6300 2750 6300 4100
Connection ~ 6300 4100
Wire Wire Line
	6300 4100 6500 4100
Wire Wire Line
	5950 3200 5950 4100
Connection ~ 5950 4100
Wire Wire Line
	5950 4100 6300 4100
Wire Wire Line
	6300 2450 6300 1300
Connection ~ 6300 1300
Wire Wire Line
	6300 1300 5950 1300
Wire Wire Line
	5950 2900 5950 1300
Connection ~ 5950 1300
Wire Wire Line
	5950 1300 5850 1300
$Comp
L Device:R_POT RV2
U 1 1 5EC2AF78
P 6300 2600
F 0 "RV2" H 6230 2646 50  0000 R CNN
F 1 "R_POT" H 6230 2555 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_ACP_CA9-V10_Vertical" H 6300 2600 50  0001 C CNN
F 3 "~" H 6300 2600 50  0001 C CNN
	1    6300 2600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5350 2950 5700 2950
Wire Wire Line
	5700 2950 5700 2600
Wire Wire Line
	5700 2600 6150 2600
Wire Wire Line
	5350 3050 5800 3050
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 5EC6C999
P 6200 3500
F 0 "J1" H 6280 3492 50  0000 L CNN
F 1 "BME280" H 6280 3401 50  0000 L CNN
F 2 "Connector_JST:JST_EH_B4B-EH-A_1x04_P2.50mm_Vertical" H 6200 3500 50  0001 C CNN
F 3 "~" H 6200 3500 50  0001 C CNN
	1    6200 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2400 6500 1300
$Comp
L Connector_Generic:Conn_01x05 J12
U 1 1 5EC381A7
P 6850 3600
F 0 "J12" H 6930 3642 50  0000 L CNN
F 1 "RTC" H 6930 3551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 6850 3600 50  0001 C CNN
F 3 "~" H 6850 3600 50  0001 C CNN
	1    6850 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 3400 6500 3400
Connection ~ 6500 3400
Wire Wire Line
	6500 3400 6500 3250
Wire Wire Line
	6650 3500 6400 3500
Wire Wire Line
	6400 3500 6400 1300
Connection ~ 6400 1300
Wire Wire Line
	6400 1300 6300 1300
Wire Wire Line
	5750 3700 5750 3800
Wire Wire Line
	5750 3800 6400 3800
Wire Wire Line
	6400 3800 6400 3600
Wire Wire Line
	6400 3600 6650 3600
Connection ~ 5750 3700
Wire Wire Line
	5650 3600 5650 3900
Wire Wire Line
	5650 3900 6450 3900
Wire Wire Line
	6450 3900 6450 3700
Wire Wire Line
	6450 3700 6650 3700
Connection ~ 5650 3600
NoConn ~ 6650 3800
$EndSCHEMATC
