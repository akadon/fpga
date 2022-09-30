 library ieee;
 use ieee.std_logic_1164.all;
 
 entity TEIL1 is
	port(
	M: in std_logic;
	S: in std_logic;
	Ee:in std_logic;
	
	D: out  std_logic;
	Ea: out std_logic;
	MGS:out std_logic
	);
end entity TEIL1;

architecture VERHALTEN of TEIL1 is

begin 
	Ea <= (S and (not M)) or ((not M) and Ee) or (S and Ee);
	D <= ((not M) and (not S) and Ee) or ((not M) and S and (not Ee)) or (M and (not S) and (not Ee));
	MGS <= ((not M) and (not S)) or (M and S);
end architecture VERHALTEN;
