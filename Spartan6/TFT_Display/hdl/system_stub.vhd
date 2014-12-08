-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    RS232_Uart_1_sout : out std_logic;
    RS232_Uart_1_sin : in std_logic;
    RESET : in std_logic;
    MCB_DDR2_rzq : inout std_logic;
    MCB_DDR2_dram_we_n : out std_logic;
    MCB_DDR2_dram_udqs : inout std_logic;
    MCB_DDR2_dram_udm : out std_logic;
    MCB_DDR2_dram_ras_n : out std_logic;
    MCB_DDR2_dram_ldm : out std_logic;
    MCB_DDR2_dram_dqs : inout std_logic;
    MCB_DDR2_dram_dq : inout std_logic_vector(15 downto 0);
    MCB_DDR2_dram_clk_n : out std_logic;
    MCB_DDR2_dram_clk : out std_logic;
    MCB_DDR2_dram_cke : out std_logic;
    MCB_DDR2_dram_cas_n : out std_logic;
    MCB_DDR2_dram_ba : out std_logic_vector(1 downto 0);
    MCB_DDR2_dram_addr : out std_logic_vector(12 downto 0);
    CLKIN : in std_logic;
    TFT_RST_BLCNT_GPIO_IO_pin : inout std_logic_vector(1 downto 0);
    axi_spi_0_SCK_pin : inout std_logic;
    axi_spi_0_MISO_pin : inout std_logic;
    axi_spi_0_MOSI_pin : inout std_logic;
    axi_spi_0_SS_pin : inout std_logic;
    tft_ctrl_0_LCD_CS_pin : out std_logic;
    tft_ctrl_0_LCD_RS_pin : out std_logic;
    tft_ctrl_0_LCD_WR_pin : out std_logic;
    tft_ctrl_0_LCD_RD_pin : out std_logic;
    tft_ctrl_0_DB_BUS_pin : out std_logic_vector(15 downto 0)
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      RS232_Uart_1_sout : out std_logic;
      RS232_Uart_1_sin : in std_logic;
      RESET : in std_logic;
      MCB_DDR2_rzq : inout std_logic;
      MCB_DDR2_dram_we_n : out std_logic;
      MCB_DDR2_dram_udqs : inout std_logic;
      MCB_DDR2_dram_udm : out std_logic;
      MCB_DDR2_dram_ras_n : out std_logic;
      MCB_DDR2_dram_ldm : out std_logic;
      MCB_DDR2_dram_dqs : inout std_logic;
      MCB_DDR2_dram_dq : inout std_logic_vector(15 downto 0);
      MCB_DDR2_dram_clk_n : out std_logic;
      MCB_DDR2_dram_clk : out std_logic;
      MCB_DDR2_dram_cke : out std_logic;
      MCB_DDR2_dram_cas_n : out std_logic;
      MCB_DDR2_dram_ba : out std_logic_vector(1 downto 0);
      MCB_DDR2_dram_addr : out std_logic_vector(12 downto 0);
      CLKIN : in std_logic;
      TFT_RST_BLCNT_GPIO_IO_pin : inout std_logic_vector(1 downto 0);
      axi_spi_0_SCK_pin : inout std_logic;
      axi_spi_0_MISO_pin : inout std_logic;
      axi_spi_0_MOSI_pin : inout std_logic;
      axi_spi_0_SS_pin : inout std_logic;
      tft_ctrl_0_LCD_CS_pin : out std_logic;
      tft_ctrl_0_LCD_RS_pin : out std_logic;
      tft_ctrl_0_LCD_WR_pin : out std_logic;
      tft_ctrl_0_LCD_RD_pin : out std_logic;
      tft_ctrl_0_DB_BUS_pin : out std_logic_vector(15 downto 0)
    );
  end component;

  attribute BOX_TYPE : STRING;
  attribute BOX_TYPE of system : component is "user_black_box";

begin

  system_i : system
    port map (
      RS232_Uart_1_sout => RS232_Uart_1_sout,
      RS232_Uart_1_sin => RS232_Uart_1_sin,
      RESET => RESET,
      MCB_DDR2_rzq => MCB_DDR2_rzq,
      MCB_DDR2_dram_we_n => MCB_DDR2_dram_we_n,
      MCB_DDR2_dram_udqs => MCB_DDR2_dram_udqs,
      MCB_DDR2_dram_udm => MCB_DDR2_dram_udm,
      MCB_DDR2_dram_ras_n => MCB_DDR2_dram_ras_n,
      MCB_DDR2_dram_ldm => MCB_DDR2_dram_ldm,
      MCB_DDR2_dram_dqs => MCB_DDR2_dram_dqs,
      MCB_DDR2_dram_dq => MCB_DDR2_dram_dq,
      MCB_DDR2_dram_clk_n => MCB_DDR2_dram_clk_n,
      MCB_DDR2_dram_clk => MCB_DDR2_dram_clk,
      MCB_DDR2_dram_cke => MCB_DDR2_dram_cke,
      MCB_DDR2_dram_cas_n => MCB_DDR2_dram_cas_n,
      MCB_DDR2_dram_ba => MCB_DDR2_dram_ba,
      MCB_DDR2_dram_addr => MCB_DDR2_dram_addr,
      CLKIN => CLKIN,
      TFT_RST_BLCNT_GPIO_IO_pin => TFT_RST_BLCNT_GPIO_IO_pin,
      axi_spi_0_SCK_pin => axi_spi_0_SCK_pin,
      axi_spi_0_MISO_pin => axi_spi_0_MISO_pin,
      axi_spi_0_MOSI_pin => axi_spi_0_MOSI_pin,
      axi_spi_0_SS_pin => axi_spi_0_SS_pin,
      tft_ctrl_0_LCD_CS_pin => tft_ctrl_0_LCD_CS_pin,
      tft_ctrl_0_LCD_RS_pin => tft_ctrl_0_LCD_RS_pin,
      tft_ctrl_0_LCD_WR_pin => tft_ctrl_0_LCD_WR_pin,
      tft_ctrl_0_LCD_RD_pin => tft_ctrl_0_LCD_RD_pin,
      tft_ctrl_0_DB_BUS_pin => tft_ctrl_0_DB_BUS_pin
    );

end architecture STRUCTURE;

