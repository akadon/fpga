library ieee;
use ieee.std_logic_1164.all;

entity TEIL2 is

	generic
	(
		N : natural :=8
	);

	port
	(
		CLOCK_50 : in std_logic;
		KEY : in std_logic_vector (3 downto 0);		-- Rücksetzen des Zählers über KEY0 (RESET)
		SW : in std_logic_vector (17 downto 0); 		
		
		LEDR : out std_logic_vector (17 downto 0) := (others => '0');
		LEDG : out std_logic_vector ((N-1) downto 0); -- Ergebnis
		HEX0 : out std_logic_vector (6 downto 0)
		
	);
	
end entity TEIL2;

architecture VERHALTEN of TEIL2 is

	component clk_div IS
		port
		(
		clock_50Mhz				: IN	STD_LOGIC;
		clock_1MHz				: OUT	STD_LOGIC;
		clock_100KHz			: OUT	STD_LOGIC;
		clock_10KHz				: OUT	STD_LOGIC;
		clock_1KHz				: OUT	STD_LOGIC;
		clock_100Hz				: OUT	STD_LOGIC;
		clock_10Hz				: OUT	STD_LOGIC;
		clock_1Hz				: OUT	STD_LOGIC
		);
	end component clk_div;
	
	signal TAKT : std_logic;
	signal EINGABE : std_logic_vector(7 downto 0);
	signal output1 : std_logic_vector(14 downto 0);
	signal STOP  : natural := 0;
	
	begin 
	
		TAKT_1_Hz : clk_div port map (CLOCK_50, open, open, open, open, open, open, TAKT);
		LEDR(17) <= TAKT;
		
	JOHN : process(TAKT,KEY(0)) is 
	
	variable REG	: std_logic_vector ((N-1) downto 0);
	
	
		begin 
		
		if KEY(0) = ('0') then 
										REG := (others => '0');
										STOP <= 0;
		
		elsif rising_edge(TAKT) then
		
			if(SW(17)=('1')) and (STOP <15) then	
			
				REG :=  REG((N-2) downto 0) & not(REG(N-1));		--vorwärtszählen
				STOP <= STOP+1;
			
				elsif (SW(17)='0') then 
			
				REG := not REG(0) & REG ((N-1) downto 1);		--rückwärtszählen
					
			end if;
			
		end if;
					
			
			 --LEDG <= REG;	

			ZAEHLERZUSTAENDE: case REG is 
			when "00000000" => HEX0 <= "1000000";
			when "00000001" => HEX0 <= "1111001";
			when "00000011" => HEX0 <= "0100100";
			when "00000111" => HEX0 <= "0110000";
			when "00001111" => HEX0 <= "0011001";
			when "00011111" => HEX0 <= "0010010";
			when "00111111" => HEX0 <= "0000010";
			when "01111111" => HEX0 <= "1111000";
			when "11111111" => HEX0 <= "0000000";
			when "11111110" => HEX0 <= "0010000";
			when "11111100" => HEX0 <= "0001000"; --A
			when "11111000" => HEX0 <= "0000011"; --B
			when "11110000" => HEX0 <= "1000110"; --C
			when "11100000" => HEX0 <= "0100001"; --D
			when "11000000" => HEX0 <= "0000110"; --E
			when "10000000" => HEX0 <= "0001110"; --F
			when others 	 => HEX0 <= "1111111";	
						
			end case;

			
		end process JOHN;
			

			LEDG 		<= '0' & SW(6 downto 0);
			EINGABE  <=	'0' & SW(6 downto 0);
			
-- Rechtsschiebend
					
--	MULTI : process (TAKT, KEY(0)) 
--	
--				variable R : std_logic_vector (7 downto 0);
--			
--				
--				begin 		
--				
--					
--					if (KEY(0)='0') then R := (others => '0');
--					elsif rising_edge (TAKT) then
--					
--					output1(14-stop) <= SW(6-stop) xor R(6) xor R(5) xor R(4) xor R(2) xor R(1);
--					R := sw(6-stop) & R(7 downto 1);
--					end if;
--							
--					
--					end process MULTI;
--					
--					LEDR(14 downto 0)  <=output1;
--					LEDG(6 downto 0)  <= SW(6 downto 0);
--					
	-- LINKSSCHIEBEND
	
	multi2 : process (TAKT,KEY(0)) 
	
	variable R : std_logic_vector(7 downto 0);
	
	begin
	
	if KEY(0) = ('0') then R := (others => '0');
	elsif rising_edge(TAKT) then
	
	output1(14-stop) <=sw(6-stop) xor R(7);
	R(7) := R(6);
	R(6) := sw(6-stop) xor R(5);
	R(5) := sw(6-stop) xor R(4);
	R(4) := sw(6-stop) xor R(3);
	R(3) := R(2);
	R(2) := sw(6-stop) xor R(1);
	R(1) := sw(6-stop) xor R(0);
	R(0) := '0';
	end if ;
	
	end process multi2;
	LEDR(14 downto 0)  <=output1;
	LEDG(6 downto 0)  <= SW(6 downto 0);
	
end architecture VERHALTEN;