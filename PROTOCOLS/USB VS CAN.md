USB (Universal Serial Bus) is a widely used industry-standard interface for connecting peripherals to computers, smartphones, and other digital devices. 
### How USB Works

1. **Physical Connection**:
   - USB uses a cable with four wires: two for power (VCC and GND) and two for data (D+ and D-).
   - Connections are typically point-to-point between a host (computer or device with USB host capability) and a peripheral (device like a keyboard, mouse, printer, etc.).

2. **Protocols and Data Transfer**:
   - USB uses a master-slave protocol where the host initiates communication and controls data transfer.
   - Data transfer rates vary with different USB versions:
     - USB 1.1/2.0: Up to 12 Mbps (Full Speed) or 480 Mbps (High Speed).
     - USB 3.x: Up to 5 Gbps (SuperSpeed) or 10 Gbps (SuperSpeed+).

3. **Power Delivery**:
   - USB also provides power to connected devices, typically 5V DC.
   - USB Power Delivery (USB PD) standard extends this capability to higher voltages and currents for charging laptops and other power-hungry devices.

4. **Data Types**:
   - USB supports various data types, from simple keyboard and mouse inputs to high-speed data transfers for storage devices and multimedia streaming.

5. **Plug-and-Play**:
   - USB devices are designed for easy plug-and-play operation.

### Advantages of USB over CAN

1. **Versatility**:
   - USB is versatile and supports a wide range of peripherals and data types, from keyboards and mice to external storage drives and audio interfaces.(but none of these fancy peripherals are relavant to the rover!).

2. **Higher Data Transfer Rates**:
   - USB offers significantly higher data transfer rates compared to traditional CAN bus systems, especially with USB 3.x and later versions.

3. **Ease of Use**:
   - USB connections are straightforward, with simple plug-and-play functionality that allows users to connect devices without needing specialized knowledge.

4. **Power Delivery**:
   - USB provides power to connected devices, simplifying the design and installation of peripherals.

5. **Ubiquity**:
   - USB ports are standard on most computers and consumer electronics, making it widely accessible and compatible across different platforms.

### Disadvantages of USB compared to CAN

1. **Point-to-Point Communication**:
   - USB is primarily designed for point-to-point communication between a host and a peripheral. It does not support multi-master or broadcast communication like CAN.

2. **Latency and Determinism**:
   - ==USB communication is not as deterministic as CAN, which is crucial in real-time applications where precise timing and guaranteed delivery of messages are required.==

3. **Limited Distance**:
   - USB cables have limited maximum lengths (typically up to 5 meters for USB 3.x without active extension), whereas CAN bus supports longer cable runs (up to several hundred meters depending on the baud rate and network topology).

4. **Complexity and Overhead**:
   - USB communication involves more protocol overhead compared to CAN, which can affect performance in certain applications.

5. **Cost**:
   - Implementing USB in embedded systems can be more expensive due to the need for host controllers and additional circuitry compared to simpler CAN bus interfaces.

### Summary

USB provides high-speed data transfer, power delivery, and versatility suitable for a wide range of consumer and computing applications. However, it lacks the deterministic communication and robustness of CAN, which is critical in applications requiring real-time responsiveness, reliability, and the ability to handle electromagnetic interference and rugged environments.

### CONCLUSION
So overall CAN is a better choice. 
***(1)*** Since our rover is a multi-master setup(and not a typical master-slave setup) and in such configurations CAN is the best choice.

***(2)*** On the rover there will be a stream of inputs/feedbacks going to the JETSON, but we need to prioritize them according to our needs(i.e some Arbitration is needed). This can only be implemented by CAN.

***(3)*** Also we need a protocol immune to the noise/EMI from other factors.

***(4)*** We need inbuilt error handling feature of CAN.