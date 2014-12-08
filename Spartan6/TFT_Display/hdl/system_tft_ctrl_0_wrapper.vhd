-------------------------------------------------------------------------------
-- system_tft_ctrl_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_tft_ctrl_0_wrapper is
  port (
    FSL_Clk : in std_logic;
    FSL_Rst : in std_logic;
    FSL_S_Clk : in std_logic;
    FSL_S_Read : out std_logic;
    FSL_S_Data : in std_logic_vector(0 to 31);
    FSL_S_Control : in std_logic;
    FSL_S_Exists : in std_logic;
    LCD_CS : out std_logic;
    LCD_RS : out std_logic;
    LCD_WR : out std_logic;
    LCD_RD : out std_logic;
    DB_BUS : out std_logic_vector(15 downto 0)
  );
end system_tft_ctrl_0_wrapper;

architecture STRUCTURE of system_tft_ctrl_0_wrapper is

  component tft_ctrl is
    port (
      FSL_Clk : in std_logic;
      FSL_Rst : in std_logic;
      FSL_S_Clk : in std_logic;
      FSL_S_Read : out std_logic;
      FSL_S_Data : in std_logic_vector(0 to 31);
      FSL_S_Control : in std_logic;
      FSL_S_Exists : in std_logic;
      LCD_CS : out std_logic;
      LCD_RS : out std_logic;
      LCD_WR : out std_logic;
      LCD_RD : out std_logic;
      DB_BUS : out std_logic_vector(15 downto 0)
    );
  end component;

begin

  tft_ctrl_0 : tft_ctrl
    port map (
      FSL_Clk => FSL_Clk,
      FSL_Rst => FSL_Rst,
      FSL_S_Clk => FSL_S_Clk,
      FSL_S_Read => FSL_S_Read,
      FSL_S_Data => FSL_S_Data,
      FSL_S_Control => FSL_S_Control,
      FSL_S_Exists => FSL_S_Exists,
      LCD_CS => LCD_CS,
      LCD_RS => LCD_RS,
      LCD_WR => LCD_WR,
      LCD_RD => LCD_RD,
      DB_BUS => DB_BUS
    );

end architecture STRUCTURE;

