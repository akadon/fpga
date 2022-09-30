 library ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

entity Teil2 is
	port
	(
		SW_BLAU : in std_logic_vector(3 downto 0);
		SW_ROT : in std_logic_vector(3 downto 0);
		
		LEDR: out std_logic_vector(17 downto 0);
		LEDG: out std_logic_vector(4 downto 0);
		HEX7: out std_logic_vector(7 downto 0);
		HEX6: out std_logic_vector(7 downto 0);
		HEX5: out std_logic_vector(7 downto 0);
		HEX2: out std_logic_vector(7 downto 0);
		HEX1: out std_logic_vector(7 downto 0);
		HEX0: out std_logic_vector(7 downto 0);
		HEX4: out std_logic_vector(7 downto 0)
	);
end TEIL2;

architecture VERHALTEN of TEIL2 is
	component TEIL1 is
		port(
			M: in std_logic;
			S: in std_logic;
			Ee:in std_logic;
			
			D: out  std_logic;
			Ea: out  std_logic;
			MGS:out std_logic
		);
	end component TEIL1 ;
	signal equal: std_logic_vector(4 downto 0);
	signal over: std_logic_vector(4 downto 0);
	signal div	: std_logic_vector(4 downto 0);

begin
	LEDR(11 downto 8) <= SW_BLAU;
	LEDR(3 downto 0) <= SW_ROT;
	
	DIVERENT1: TEIL1 port map (SW_BLAU(0),SW_ROT(0),'0',div(0),over(0),equal(0));
	DIVERENT2: TEIL1 port map (SW_BLAU(1),SW_ROT(1),over(0),div(1),over(1),equal(1));
	DIVERENT3: TEIL1 port map (SW_BLAU(2),SW_ROT(2),over(1),div(2),over(2),equal(2));
	DIVERENT4: TEIL1 port map (SW_BLAU(3),SW_ROT(3),over(2),div(3),div(4),equal(3));
	
	LEDG <= div;
	LEDR(17) <= equal(0) and equal(1) and equal(2) and equal(3);
	
	
	hexalamp: process(SW_BLAU,SW_ROT,div) is
		begin
		MINUEND1 : case SW_BLAU is
			when x"0" => HEX7 <= "01000000";
			when x"1" => HEX7 <= "01000000";
			when x"2" => HEX7 <= "01000000";
			when x"3" => HEX7 <= "01000000";
			when x"4" => HEX7 <= "01000000";
			when x"5" => HEX7 <= "01000000";
			when x"6" => HEX7 <= "01000000";
			when x"7" => HEX7 <= "01000000";
			when x"8" => HEX7 <= "01000000";
			when x"9" => HEX7 <= "01000000";
			when x"A" => HEX7 <= "01111001";
			when x"B" => HEX7 <= "01111001";
			when x"C" => HEX7 <= "01111001";
			when x"D" => HEX7 <= "01111001";
			when x"E" => HEX7 <= "01111001";
			when x"F" => HEX7 <= "01111001";
			when others => HEX7 <= "01111111";
			end case;
			
			MINUEND2 : case SW_BLAU is
			when x"0" => HEX6 <= "01000000";
			when x"1" => HEX6 <= "01111001";
			when x"2" => HEX6 <= "00100100";
			when x"3" => HEX6 <= "00110000";
			when x"4" => HEX6 <= "00011001";
			when x"5" => HEX6 <= "00010010";
			when x"6" => HEX6 <= "00000010";
			when x"7" => HEX6 <= "01111000";
			when x"8" => HEX6 <= "00000000";
			when x"9" => HEX6 <= "00010000";
			when x"A" => HEX6 <= "01000000";
			when x"B" => HEX6 <= "01111001";
			when x"C" => HEX6 <= "00100100";
			when x"D" => HEX6 <= "00110000";
			when x"E" => HEX6 <= "00011001";
			when x"F" => HEX6 <= "00010010";
			when others => HEX6 <= "01111111";
			end case;
			
			SUBTRAHEND1 : case SW_ROT is
			when x"0" => HEX5 <= "01000000";
			when x"1" => HEX5 <= "01000000";
			when x"2" => HEX5 <= "01000000";
			when x"3" => HEX5 <= "01000000";
			when x"4" => HEX5 <= "01000000";
			when x"5" => HEX5 <= "01000000";
			when x"6" => HEX5 <= "01000000";
			when x"7" => HEX5 <= "01000000";
			when x"8" => HEX5 <= "01000000";
			when x"9" => HEX5 <= "01000000";
			when x"A" => HEX5 <= "01111001";
			when x"B" => HEX5 <= "01111001";
			when x"C" => HEX5 <= "01111001";
			when x"D" => HEX5 <= "01111001";
			when x"E" => HEX5 <= "01111001";
			when x"F" => HEX5 <= "01111001";
			when others => HEX5 <= "01111111";
			end case;
			
			SUBTRAHEND2 : case SW_ROT is
			when x"0" => HEX4 <= "01000000";
			when x"1" => HEX4 <= "01111001";
			when x"2" => HEX4 <= "00100100";
			when x"3" => HEX4 <= "00110000";
			when x"4" => HEX4 <= "00011001";
			when x"5" => HEX4 <= "00010010";
			when x"6" => HEX4 <= "00000010";
			when x"7" => HEX4 <= "01111000";
			when x"8" => HEX4 <= "00000000";
			when x"9" => HEX4 <= "00010000";
			when x"A" => HEX4 <= "01000000";
			when x"B" => HEX4 <= "01111001";
			when x"C" => HEX4 <= "00100100";
			when x"D" => HEX4 <= "00110000";
			when x"E" => HEX4 <= "00011001";
			when x"F" => HEX4 <= "00010010";
			when others => HEX4 <= "01111111";
			end case;
						
			
						
						
			ergeb1 : case div(4) is
			when '1' => HEX2 <= "00111111";
			when '0' => HEX2 <= "01111111";
			when others => HEX2 <= "01111111";
			end case;
			
			ergeb2 : case div(3 downto 0) is
			when x"0" => HEX1 <= "01000000";
			when x"1" => HEX1 <= "01000000";
			when x"2" => HEX1 <= "01000000";
			when x"3" => HEX1 <= "01000000";
			when x"4" => HEX1 <= "01000000";
			when x"5" => HEX1 <= "01000000";
			when x"6" => HEX1 <= "01000000";
			when x"7" => HEX1 <= "01000000";
			when x"8" => HEX1 <= "01000000";
			when x"9" => HEX1 <= "01000000";
			when x"A" => HEX1 <= "01111001";
			when x"B" => HEX1 <= "01111001";
			when x"C" => HEX1 <= "01111001";
			when x"D" => HEX1 <= "01111001";
			when x"E" => HEX1 <= "01111001";
			when x"F" => HEX1 <= "01111001";
			when others => HEX1 <= "01111111";
			end case;
			
						
			ergeb3 : case div(3 downto 0) is
			when x"0" => HEX0 <= "01000000";
			when x"1" => HEX0 <= "01111001";
			when x"2" => HEX0 <= "00100100";
			when x"3" => HEX0 <= "00110000";
			when x"4" => HEX0 <= "00011001";
			when x"5" => HEX0 <= "00010010";
			when x"6" => HEX0 <= "00000010";
			when x"7" => HEX0 <= "01111000";
			when x"8" => HEX0 <= "00000000";
			when x"9" => HEX0 <= "00010000";
			when x"A" => HEX0 <= "01000000";
			when x"B" => HEX0 <= "01111001";
			when x"C" => HEX0 <= "00100100";
			when x"D" => HEX0 <= "00110000";
			when x"E" => HEX0 <= "00011001";
			when x"F" => HEX0 <= "00010010";
			when others => HEX0 <= "01111111";
			end case;
			
	end process hexalamp;

	
end VERHALTEN;
