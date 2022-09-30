LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

entity TEIL2 is
	port
	(
	--Input Ports
	SW_BLAU: in std_logic_vector (3 downto 0);
	SW_ROT: in std_logic_vector (3 downto 0);
	
	--output Ports
	LEDR: out std_logic_vector (17 downto 0);
	HEX7: out std_logic_vector (6 downto 0);
	HEX6: out std_logic_vector (6 downto 0);
	HEX5: out std_logic_vector (6 downto 0);
	HEX4: out std_logic_vector (6 downto 0);
	HEX2: out std_logic_vector (6 downto 0);
	HEX1: out std_logic_vector (6 downto 0);
	HEX0: out std_logic_vector (6 downto 0);
	LEDG: out std_logic_vector (4 downto 0)
	
	
	
	
			);
			
end entity TEIL2;


architecture VERHALTEN of TEIL2 is
component TEIL1 is
	port
	(
		-- Input ports
		M,S,EE	: in  std_logic;
	


		-- Output ports
		D,EA,MGS	: out std_logic
		
	);
end component TEIL1;


Signal A : std_logic_vector (4 downto 0); --grüne LED, LEDG4 als Vorzeichen, 3 bis 0 als Differenz
Signal B : std_logic_vector (2 downto 0);	--Entleihung Eingang
Signal C : std_logic_vector (3 downto 0);	--MGS, Komparator


begin
MSB : TEIL1 port map (SW_BLAU(3),SW_ROT(3),B(2),A(3),A(4),C(3));
B_1 : TEIL1 port map (SW_BLAU(2),SW_ROT(2),B(1),A(2),B(2),C(2));
B_2 : TEIL1 port map (SW_BLAU(1),SW_ROT(1),B(0),A(1),B(1),C(1));
LSB : TEIL1 port map (SW_BLAU(0),SW_ROT(0),'0',A(0),B(0),C(0));

LEDR(11)<=SW_BLAU(3);
LEDR(10)<=SW_BLAU(2);
LEDR(9)<=SW_BLAU(1);
LEDR(8)<=SW_BLAU(0);
LEDR(3)<=SW_ROT(3);
LEDR(2)<=SW_ROT(2);
LEDR(1)<=SW_ROT(1);
LEDR(0)<=SW_ROT(0);



LEDG<=A;


LEDR(17)<= C(3) and C(2) and C(1) and C(0);
with SW_BLAU select
HEX7 <=	"1111001" when "1010" | "1011" | "1100" | "1101" | "1110" | "1111",
			"1111111" when others;



with SW_BLAU select
HEX6 <= 	"1000000" when  "0000" | "1010",
			"1111001" when  "0001" | "1011",
			"0100100" when  "0010" | "1100",
			"0110000" when  "0011" | "1101",
			"0011001" when  "0100" | "1110",
			"0010010" when  "0101" | "1111",
			"0000010" when  "0110",
			"1111000" when  "0111",
			"0000000" when  "1000",
			"0010000" when  "1001",
			"1111111" when others;
			
with SW_ROT select
HEX5 <=	"1111001" when "1010" | "1011" | "1100" | "1101" | "1110" | "1111",
			"1111111" when others;



with SW_ROT select
HEX4 <= 	"1000000" when  "0000" | "1010",
			"1111001" when  "0001" | "1011",
			"0100100" when  "0010" | "1100",
			"0110000" when  "0011" | "1101",
			"0011001" when  "0100" | "1110",
			"0010010" when  "0101" | "1111",
			"0000010" when  "0110",
			"1111000" when  "0111",
			"0000000" when  "1000",
			"0010000" when  "1001",
			"1111111" when others;
			
--Differenz ausgeben		
HEX2(5 downto 0)<="111111";	
HEX2(6)<=(not A(4));

with A select
HEX1 <=	"1111001" when "01010" | "01011" | "01100" | "01101" | "01110" | "01111" |"10110"|"10101"|"10100"|"10011"|"10010"|"10001",
			"1111111" when others;



with A select
HEX0 <= 	"1000000" when  "00000" | "01010" |"10110",
			"1111001" when  "00001" | "01011"|"11111"|"10101",
			"0100100" when  "00010" | "01100"|"11110"|"10100",
			"0110000" when  "00011" | "01101"|"11101"|"10011",
			"0011001" when  "00100" | "01110"|"11100"|"10010",
			"0010010" when  "00101" | "01111"|"11011"|"10001",
			"0000010" when  "00110"|"11010",
			"1111000" when  "00111"|"11001",
			"0000000" when  "01000"|"11000",
			"0010000" when  "01001"|"10111",
			"1111111" when others;





end architecture VERHALTEN;