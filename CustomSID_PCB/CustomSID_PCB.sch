EESchema Schematic File Version 4
LIBS:CustomSID_PCB-cache
EELAYER 26 0
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
L FeatherM0_Adalogger:FeatherM0_Adalogger U1
U 1 1 5B945213
P 2700 2050
F 0 "U1" H 2700 2150 60  0000 C CNN
F 1 "FeatherM0_Adalogger" H 2700 2050 60  0000 C CNN
F 2 "FeatherM0_Adalogger:FeatherM0_Adalogger" H 2700 2050 60  0001 C CNN
F 3 "" H 2700 2050 60  0001 C CNN
	1    2700 2050
	0    1    1    0   
$EndComp
$Comp
L Amplifier_Operational:TLC274 U4
U 1 1 5B9452FE
P 8300 1800
F 0 "U4" H 8300 2000 50  0000 L CNN
F 1 "TL974" H 8300 1600 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 8250 1900 50  0001 C CNN
F 3 "" H 8350 2000 50  0001 C CNN
	1    8300 1800
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TLC274 U4
U 2 1 5B94535F
P 8300 2650
F 0 "U4" H 8300 2850 50  0000 L CNN
F 1 "TL974" H 8300 2450 50  0000 L CNN
F 2 "" H 8250 2750 50  0001 C CNN
F 3 "" H 8350 2850 50  0001 C CNN
	2    8300 2650
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TLC274 U4
U 3 1 5B9453B0
P 8300 3400
F 0 "U4" H 8300 3600 50  0000 L CNN
F 1 "TL974" H 8300 3200 50  0000 L CNN
F 2 "" H 8250 3500 50  0001 C CNN
F 3 "" H 8350 3600 50  0001 C CNN
	3    8300 3400
	1    0    0    -1  
$EndComp
$Comp
L AD5263:AD5263 U3
U 1 1 5B946A06
P 5750 2100
F 0 "U3" H 5750 2350 60  0000 C CNN
F 1 "AD5263" H 5750 2750 60  0000 C CNN
F 2 "Package_SO:TSSOP-24_4.4x7.8mm_P0.65mm" H 5750 2350 60  0001 C CNN
F 3 "" H 5750 2350 60  0001 C CNN
	1    5750 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:DB9_Male J2
U 1 1 5B947142
P 10500 2200
F 0 "J2" H 10500 2750 50  0000 C CNN
F 1 "DB9_Female" H 10500 1625 50  0000 C CNN
F 2 "Connector_Dsub:DSUB-9_Female_Horizontal_P2.77x2.84mm_EdgePinOffset7.70mm_Housed_MountingHolesOffset9.12mm" H 10500 2200 50  0001 C CNN
F 3 "" H 10500 2200 50  0001 C CNN
	1    10500 2200
	1    0    0    1   
$EndComp
NoConn ~ 10200 2400
$Comp
L power:GND #PWR01
U 1 1 5B9471DB
P 10000 2300
F 0 "#PWR01" H 10000 2050 50  0001 C CNN
F 1 "GND" H 10000 2150 50  0000 C CNN
F 2 "" H 10000 2300 50  0001 C CNN
F 3 "" H 10000 2300 50  0001 C CNN
	1    10000 2300
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR02
U 1 1 5B947206
P 10000 2100
F 0 "#PWR02" H 10000 1950 50  0001 C CNN
F 1 "+12V" H 10000 2240 50  0000 C CNN
F 2 "" H 10000 2100 50  0001 C CNN
F 3 "" H 10000 2100 50  0001 C CNN
	1    10000 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5B947502
P 1800 1600
F 0 "#PWR09" H 1800 1350 50  0001 C CNN
F 1 "GND" H 1800 1450 50  0000 C CNN
F 2 "" H 1800 1600 50  0001 C CNN
F 3 "" H 1800 1600 50  0001 C CNN
	1    1800 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5B94755A
P 4650 1550
F 0 "#PWR010" H 4650 1300 50  0001 C CNN
F 1 "GND" H 4650 1400 50  0000 C CNN
F 2 "" H 4650 1550 50  0001 C CNN
F 3 "" H 4650 1550 50  0001 C CNN
	1    4650 1550
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR011
U 1 1 5B9475E6
P 5050 1450
F 0 "#PWR011" H 5050 1300 50  0001 C CNN
F 1 "+12V" H 5050 1590 50  0000 C CNN
F 2 "" H 5050 1450 50  0001 C CNN
F 3 "" H 5050 1450 50  0001 C CNN
	1    5050 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR012
U 1 1 5B947652
P 6650 1400
F 0 "#PWR012" H 6650 1250 50  0001 C CNN
F 1 "+12V" H 6650 1540 50  0000 C CNN
F 2 "" H 6650 1400 50  0001 C CNN
F 3 "" H 6650 1400 50  0001 C CNN
	1    6650 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5B947672
P 6900 1550
F 0 "#PWR013" H 6900 1300 50  0001 C CNN
F 1 "GND" H 6900 1400 50  0000 C CNN
F 2 "" H 6900 1550 50  0001 C CNN
F 3 "" H 6900 1550 50  0001 C CNN
	1    6900 1550
	1    0    0    -1  
$EndComp
NoConn ~ 6400 1850
NoConn ~ 6400 1950
NoConn ~ 6400 2050
NoConn ~ 6400 2250
NoConn ~ 6400 2350
Wire Wire Line
	4650 1550 4900 1550
Wire Wire Line
	5150 1850 4900 1850
Wire Wire Line
	4900 1850 4900 1550
Connection ~ 4900 1550
Wire Wire Line
	5150 1650 5050 1650
Wire Wire Line
	5050 1450 5050 1650
Wire Wire Line
	5050 1950 5150 1950
Connection ~ 5050 1650
Wire Wire Line
	6900 1550 6400 1550
Wire Wire Line
	6400 1650 6650 1650
Wire Wire Line
	6650 1650 6650 1400
$Comp
L power:+12V #PWR014
U 1 1 5B947720
P 4950 2150
F 0 "#PWR014" H 4950 2000 50  0001 C CNN
F 1 "+12V" H 4950 2290 50  0000 C CNN
F 2 "" H 4950 2150 50  0001 C CNN
F 3 "" H 4950 2150 50  0001 C CNN
	1    4950 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2150 4950 2150
$Comp
L power:GND #PWR015
U 1 1 5B947756
P 4950 2250
F 0 "#PWR015" H 4950 2000 50  0001 C CNN
F 1 "GND" H 4950 2100 50  0000 C CNN
F 2 "" H 4950 2250 50  0001 C CNN
F 3 "" H 4950 2250 50  0001 C CNN
	1    4950 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2250 5100 2250
$Comp
L power:GND #PWR016
U 1 1 5B94778D
P 6650 2150
F 0 "#PWR016" H 6650 1900 50  0001 C CNN
F 1 "GND" H 6650 2000 50  0000 C CNN
F 2 "" H 6650 2150 50  0001 C CNN
F 3 "" H 6650 2150 50  0001 C CNN
	1    6650 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 2150 6400 2150
NoConn ~ 10200 2500
$Comp
L Device:R_Small R1
U 1 1 5B947826
P 9650 1800
F 0 "R1" H 9680 1820 50  0000 L CNN
F 1 "1.8K" H 9680 1760 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9650 1800 50  0001 C CNN
F 3 "" H 9650 1800 50  0001 C CNN
	1    9650 1800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R2
U 1 1 5B9478A3
P 9650 2000
F 0 "R2" H 9680 2020 50  0000 L CNN
F 1 "1.8K" H 9680 1960 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9650 2000 50  0001 C CNN
F 3 "" H 9650 2000 50  0001 C CNN
	1    9650 2000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R3
U 1 1 5B9478E0
P 9650 2200
F 0 "R3" H 9680 2220 50  0000 L CNN
F 1 "470" H 9680 2160 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 9650 2200 50  0001 C CNN
F 3 "" H 9650 2200 50  0001 C CNN
	1    9650 2200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10200 1800 9750 1800
Wire Wire Line
	10200 2000 9750 2000
Wire Wire Line
	10200 2200 9750 2200
Wire Wire Line
	8600 1800 8700 1800
Wire Wire Line
	8600 2650 8700 2650
Wire Wire Line
	9000 2000 9550 2000
Wire Wire Line
	8600 3400 8700 3400
Wire Wire Line
	9250 2200 9550 2200
$Comp
L Regulator_Switching:TSR_1-2450 U2
U 1 1 5B947E76
P 5650 3650
F 0 "U2" H 5650 3800 50  0000 C CNN
F 1 "TSR 1-2450" H 5450 3950 50  0000 L CNN
F 2 "Converter_DCDC:Converter_DCDC_TRACO_TSR-1_THT" H 5650 3875 50  0001 C CIN
F 3 "" H 5650 3600 50  0001 C CNN
	1    5650 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR017
U 1 1 5B947EE1
P 5250 3550
F 0 "#PWR017" H 5250 3400 50  0001 C CNN
F 1 "+12V" H 5250 3690 50  0000 C CNN
F 2 "" H 5250 3550 50  0001 C CNN
F 3 "" H 5250 3550 50  0001 C CNN
	1    5250 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5B947F0A
P 5650 3850
F 0 "#PWR018" H 5650 3600 50  0001 C CNN
F 1 "GND" H 5650 3700 50  0000 C CNN
F 2 "" H 5650 3850 50  0001 C CNN
F 3 "" H 5650 3850 50  0001 C CNN
	1    5650 3850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR019
U 1 1 5B947F2B
P 6050 3550
F 0 "#PWR019" H 6050 3400 50  0001 C CNN
F 1 "+5V" H 6050 3690 50  0000 C CNN
F 2 "" H 6050 3550 50  0001 C CNN
F 3 "" H 6050 3550 50  0001 C CNN
	1    6050 3550
	1    0    0    -1  
$EndComp
$Comp
L Connector:RJ45_LED_Shielded J1
U 1 1 5B94806D
P 4500 3850
F 0 "J1" H 4500 4250 50  0000 C CNN
F 1 "Ethernet_Jack" H 4500 3350 50  0000 C CNN
F 2 "Connector_RJ:RJ45_Amphenol_RJHSE538X" H 4500 3850 50  0001 C CNN
F 3 "" H 4500 3850 50  0001 C CNN
	1    4500 3850
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5B948226
P 3900 3550
F 0 "#PWR020" H 3900 3300 50  0001 C CNN
F 1 "GND" H 3900 3400 50  0000 C CNN
F 2 "" H 3900 3550 50  0001 C CNN
F 3 "" H 3900 3550 50  0001 C CNN
	1    3900 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3550 3900 3550
$Comp
L power:+5V #PWR021
U 1 1 5B948295
P 4050 3450
F 0 "#PWR021" H 4050 3300 50  0001 C CNN
F 1 "+5V" H 4050 3590 50  0000 C CNN
F 2 "" H 4050 3450 50  0001 C CNN
F 3 "" H 4050 3450 50  0001 C CNN
	1    4050 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3650 4050 3650
Wire Wire Line
	4050 3650 4050 3450
NoConn ~ 4100 4250
NoConn ~ 4100 4150
NoConn ~ 4100 4050
NoConn ~ 4100 3950
NoConn ~ 4100 3850
Wire Wire Line
	8700 1800 8700 2100
Wire Wire Line
	8700 2100 7900 2100
Wire Wire Line
	7900 2100 7900 1900
Wire Wire Line
	7900 1900 8000 1900
Connection ~ 8700 1800
Wire Wire Line
	8700 2650 8700 2950
Wire Wire Line
	8700 2950 7900 2950
Wire Wire Line
	7900 2950 7900 2750
Wire Wire Line
	7900 2750 8000 2750
Connection ~ 8700 2650
Wire Wire Line
	8700 3400 8700 3700
Wire Wire Line
	8700 3700 7900 3700
Wire Wire Line
	7900 3700 7900 3500
Wire Wire Line
	7900 3500 8000 3500
Connection ~ 8700 3400
Text Label 4200 1750 0    60   ~ 0
SPEED
Wire Wire Line
	5150 1750 4200 1750
Wire Wire Line
	5150 2050 4200 2050
Wire Wire Line
	6400 1750 7300 1750
Text Label 4200 2050 0    60   ~ 0
REF
Text Label 7300 1750 2    60   ~ 0
DIR
Text Label 8000 1700 2    60   ~ 0
SPEED
Text Label 8000 2550 2    60   ~ 0
DIR
Text Label 8000 3300 2    60   ~ 0
REF
$Comp
L power:+3V3 #PWR022
U 1 1 5B95364C
P 4700 2450
F 0 "#PWR022" H 4700 2300 50  0001 C CNN
F 1 "+3V3" H 4700 2590 50  0000 C CNN
F 2 "" H 4700 2450 50  0001 C CNN
F 3 "" H 4700 2450 50  0001 C CNN
	1    4700 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2450 4700 2450
Wire Wire Line
	2050 1600 1800 1600
$Comp
L power:+3V3 #PWR023
U 1 1 5B95383E
P 1800 1400
F 0 "#PWR023" H 1800 1250 50  0001 C CNN
F 1 "+3V3" H 1800 1540 50  0000 C CNN
F 2 "" H 1800 1400 50  0001 C CNN
F 3 "" H 1800 1400 50  0001 C CNN
	1    1800 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 1400 1800 1400
$Comp
L power:+5V #PWR024
U 1 1 5B953903
P 3600 1900
F 0 "#PWR024" H 3600 1750 50  0001 C CNN
F 1 "+5V" H 3600 2040 50  0000 C CNN
F 2 "" H 3600 1900 50  0001 C CNN
F 3 "" H 3600 1900 50  0001 C CNN
	1    3600 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2350 5100 2350
Wire Wire Line
	5100 2350 5100 2250
Connection ~ 5100 2250
Wire Wire Line
	6400 2650 6500 2650
Wire Wire Line
	6500 2650 6500 2800
Wire Wire Line
	6500 2800 4150 2800
Wire Wire Line
	3750 2550 5150 2550
Wire Wire Line
	3350 2500 3500 2500
Wire Wire Line
	3500 2500 3500 3750
Wire Wire Line
	3500 3750 4100 3750
Wire Wire Line
	2050 2300 1700 2300
Wire Wire Line
	1700 2300 1700 3200
Wire Wire Line
	1700 3200 3850 3200
Wire Wire Line
	3850 3200 3850 2650
Wire Wire Line
	3850 2650 5150 2650
Wire Wire Line
	2050 2400 1800 2400
Wire Wire Line
	1800 2400 1800 3100
Wire Wire Line
	1800 3100 3750 3100
Wire Wire Line
	3750 3100 3750 2550
NoConn ~ 2050 2200
NoConn ~ 2050 2100
NoConn ~ 2050 2000
$Comp
L Device:R_POT RV1
U 1 1 5B954604
P 1200 1400
F 0 "RV1" V 1025 1400 50  0000 C CNN
F 1 "DISPLAY_SPEED" V 1100 1400 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3386P_Vertical" H 1200 1400 50  0001 C CNN
F 3 "" H 1200 1400 50  0001 C CNN
	1    1200 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV2
U 1 1 5B954657
P 1200 2200
F 0 "RV2" V 1025 2200 50  0000 C CNN
F 1 "DISPLAY_BRIGHTNESS" V 1100 2200 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3386P_Vertical" H 1200 2200 50  0001 C CNN
F 3 "" H 1200 2200 50  0001 C CNN
	1    1200 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR026
U 1 1 5B95469A
P 1200 1250
F 0 "#PWR026" H 1200 1100 50  0001 C CNN
F 1 "+3V3" H 1200 1390 50  0000 C CNN
F 2 "" H 1200 1250 50  0001 C CNN
F 3 "" H 1200 1250 50  0001 C CNN
	1    1200 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR027
U 1 1 5B9546CC
P 1200 2050
F 0 "#PWR027" H 1200 1900 50  0001 C CNN
F 1 "+3V3" H 1200 2190 50  0000 C CNN
F 2 "" H 1200 2050 50  0001 C CNN
F 3 "" H 1200 2050 50  0001 C CNN
	1    1200 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR028
U 1 1 5B954713
P 1200 1550
F 0 "#PWR028" H 1200 1300 50  0001 C CNN
F 1 "GND" H 1200 1400 50  0000 C CNN
F 2 "" H 1200 1550 50  0001 C CNN
F 3 "" H 1200 1550 50  0001 C CNN
	1    1200 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 5B954745
P 1200 2350
F 0 "#PWR029" H 1200 2100 50  0001 C CNN
F 1 "GND" H 1200 2200 50  0000 C CNN
F 2 "" H 1200 2350 50  0001 C CNN
F 3 "" H 1200 2350 50  0001 C CNN
	1    1200 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1400 1500 1400
Wire Wire Line
	1500 1400 1500 1700
Wire Wire Line
	1500 1700 2050 1700
Wire Wire Line
	1350 2200 1500 2200
Wire Wire Line
	1500 2200 1500 1800
Wire Wire Line
	1500 1800 2050 1800
NoConn ~ 3350 1800
NoConn ~ 3350 2000
NoConn ~ 3350 2100
NoConn ~ 3350 2600
NoConn ~ 3350 2700
NoConn ~ 3350 2800
NoConn ~ 2050 2800
NoConn ~ 2050 2700
NoConn ~ 2050 2600
NoConn ~ 2050 2500
$Comp
L power:GND #PWR030
U 1 1 5B95B9E0
P 5650 4600
F 0 "#PWR030" H 5650 4350 50  0001 C CNN
F 1 "GND" H 5650 4450 50  0000 C CNN
F 2 "" H 5650 4600 50  0001 C CNN
F 3 "" H 5650 4600 50  0001 C CNN
	1    5650 4600
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR031
U 1 1 5B95BA12
P 6050 4600
F 0 "#PWR031" H 6050 4450 50  0001 C CNN
F 1 "+12V" H 6050 4740 50  0000 C CNN
F 2 "" H 6050 4600 50  0001 C CNN
F 3 "" H 6050 4600 50  0001 C CNN
	1    6050 4600
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG032
U 1 1 5B95BB39
P 5650 4600
F 0 "#FLG032" H 5650 4675 50  0001 C CNN
F 1 "PWR_FLAG" H 5650 4750 50  0000 C CNN
F 2 "" H 5650 4600 50  0001 C CNN
F 3 "" H 5650 4600 50  0001 C CNN
	1    5650 4600
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG033
U 1 1 5B95BB72
P 6050 4600
F 0 "#FLG033" H 6050 4675 50  0001 C CNN
F 1 "PWR_FLAG" H 6050 4750 50  0000 C CNN
F 2 "" H 6050 4600 50  0001 C CNN
F 3 "" H 6050 4600 50  0001 C CNN
	1    6050 4600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4900 1550 5150 1550
Wire Wire Line
	5050 1650 5050 1950
Wire Wire Line
	8700 1800 9550 1800
Wire Wire Line
	8700 2650 9000 2650
Wire Wire Line
	8700 3400 9250 3400
Wire Wire Line
	5100 2250 5150 2250
$Comp
L Amplifier_Operational:TLC274 U4
U 5 1 5B9634F8
P 9600 3400
F 0 "U4" H 9600 3600 50  0000 L CNN
F 1 "TL974" H 9600 3200 50  0000 L CNN
F 2 "" H 9550 3500 50  0001 C CNN
F 3 "" H 9650 3600 50  0001 C CNN
	5    9600 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR03
U 1 1 5B96361E
P 9500 3100
F 0 "#PWR03" H 9500 2950 50  0001 C CNN
F 1 "+12V" H 9500 3240 50  0000 C CNN
F 2 "" H 9500 3100 50  0001 C CNN
F 3 "" H 9500 3100 50  0001 C CNN
	1    9500 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5B963653
P 9500 3700
F 0 "#PWR04" H 9500 3450 50  0001 C CNN
F 1 "GND" H 9500 3550 50  0000 C CNN
F 2 "" H 9500 3700 50  0001 C CNN
F 3 "" H 9500 3700 50  0001 C CNN
	1    9500 3700
	1    0    0    -1  
$EndComp
NoConn ~ 10200 2600
Wire Wire Line
	9000 2000 9000 2650
Wire Wire Line
	9250 2200 9250 3400
Text Label 1950 3200 0    50   ~ 0
SCK
Text Label 1950 3100 0    50   ~ 0
MOSI
Text Label 6250 2800 0    50   ~ 0
CS
Text Label 8700 3400 0    50   ~ 0
REF_BUF
Text Label 8700 2650 0    50   ~ 0
DIR_BUF
Text Label 8700 1800 0    50   ~ 0
SPEED_BUF
NoConn ~ 3350 1700
NoConn ~ 6800 450 
NoConn ~ 6300 2450
Wire Wire Line
	6400 2450 6900 2450
Wire Wire Line
	4250 2300 4250 2900
Wire Wire Line
	4250 2900 6600 2900
Wire Wire Line
	6600 2900 6600 2550
Wire Wire Line
	6400 2550 6600 2550
Text Label 6250 2900 0    50   ~ 0
RES
Wire Wire Line
	4150 2800 4150 2400
Wire Wire Line
	4150 2400 3350 2400
Wire Wire Line
	3350 2300 4250 2300
$Comp
L Device:R_Small R4
U 1 1 5B9CF8C9
P 6600 3000
F 0 "R4" H 6630 3020 50  0000 L CNN
F 1 "10k" H 6630 2960 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 6600 3000 50  0001 C CNN
F 3 "" H 6600 3000 50  0001 C CNN
	1    6600 3000
	1    0    0    -1  
$EndComp
Connection ~ 6600 2900
$Comp
L power:GND #PWR05
U 1 1 5B9CFA16
P 6600 3100
F 0 "#PWR05" H 6600 2850 50  0001 C CNN
F 1 "GND" H 6600 2950 50  0000 C CNN
F 2 "" H 6600 3100 50  0001 C CNN
F 3 "" H 6600 3100 50  0001 C CNN
	1    6600 3100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0101
U 1 1 5B9C3060
P 6900 2450
F 0 "#PWR0101" H 6900 2300 50  0001 C CNN
F 1 "+3V3" H 6900 2590 50  0000 C CNN
F 2 "" H 6900 2450 50  0001 C CNN
F 3 "" H 6900 2450 50  0001 C CNN
	1    6900 2450
	1    0    0    -1  
$EndComp
$Comp
L Connector:AudioJack2_Ground_Switch J3
U 1 1 5B9E71AC
P 1100 3100
F 0 "J3" H 1104 3442 50  0000 C CNN
F 1 "AudioJack2_Ground_Switch" H 1104 3351 50  0000 C CNN
F 2 "AudioJack:AudioJack" H 1100 3100 50  0001 C CNN
F 3 "~" H 1100 3100 50  0001 C CNN
	1    1100 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 1900 1600 1900
Wire Wire Line
	1600 3100 1300 3100
NoConn ~ 1300 3200
$Comp
L power:GND #PWR06
U 1 1 5B9EC7D3
P 1450 3250
F 0 "#PWR06" H 1450 3000 50  0001 C CNN
F 1 "GND" H 1450 3100 50  0000 C CNN
F 2 "" H 1450 3250 50  0001 C CNN
F 3 "" H 1450 3250 50  0001 C CNN
	1    1450 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3250 1450 3000
Wire Wire Line
	1450 3000 1300 3000
$Comp
L Device:R_Small R5
U 1 1 5B9EF625
P 1600 2550
F 0 "R5" H 1630 2570 50  0000 L CNN
F 1 "1k" H 1630 2510 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1600 2550 50  0001 C CNN
F 3 "" H 1600 2550 50  0001 C CNN
	1    1600 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	1600 1900 1600 2450
Wire Wire Line
	1600 2650 1600 3100
NoConn ~ 4900 3550
NoConn ~ 4900 3650
NoConn ~ 4900 4250
NoConn ~ 4900 4150
$Comp
L power:GND #PWR0102
U 1 1 5BA09AC5
P 4850 3200
F 0 "#PWR0102" H 4850 2950 50  0001 C CNN
F 1 "GND" H 4850 3050 50  0000 C CNN
F 2 "" H 4850 3200 50  0001 C CNN
F 3 "" H 4850 3200 50  0001 C CNN
	1    4850 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3200 4500 3200
Wire Wire Line
	4500 3200 4500 3350
Text Label 3600 3750 0    50   ~ 0
TX
Wire Wire Line
	10200 2300 10000 2300
Wire Wire Line
	10000 2100 10200 2100
Text Label 10200 1900 2    50   ~ 0
MODE
Text Label 3350 2200 0    50   ~ 0
MODE
Wire Wire Line
	3350 1900 3600 1900
$EndSCHEMATC
