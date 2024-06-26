UART (Universal Asynchronous Receiver/Transmitter) is a widely used serial communication protocol for transmitting and receiving data between devices. 

### How UART Works

1. **Asynchronous Communication**: UART operates asynchronously, meaning there is no clock signal shared between the transmitter and receiver. Instead, both ends must agree on a common baud rate (bits per second).

2. **Data Format**:
   - **Start Bit**: Signals the beginning of a data frame. Typically, it is a single bit set to '0'.
   - **Data Bits**: The actual data, usually between 5 and 9 bits.
   - **Parity Bit (Optional)**: Used for error checking. Can be even, odd, or none.
   - **Stop Bits**: Signals the end of the data frame. Can be 1, 1.5, or 2 bits.

3. **Transmission**:
   - When the UART transmitter is ready to send data, it pulls the transmission line (TX) low for the start bit.
   - It then sends the data bits one by one, followed by the optional parity bit and stop bits.
   - The UART receiver detects the start bit and begins reading the incoming bits at the agreed baud rate.

4. **Reception**:
   - The receiver uses its own clock to sample the incoming bits.
   - It waits for the start bit, reads the data bits, checks the parity (if used), and looks for the stop bits to complete the frame.

### Advantages of UART
- **Simplicity**: UART is straightforward to implement with minimal hardware requirements.
- **Point-to-Point Communication**: Ideal for direct communication between two devices.
- **Asynchronous**: No need for a shared clock signal, simplifying connections.
- **Wide Availability**: Widely supported across various microcontrollers and devices.

### Disadvantages of UART
- **Limited Distance and Speed**: UART is typically used for short-distance communication with limited speed (up to a few Mbps).
- **Point-to-Point Only**: Not suitable for complex network topologies without additional hardware.(i.e cant support Multi-Master/Slave Configuration).
- **Lack of Error Handling**: Limited built-in error detection and correction mechanisms compared to more robust protocols like CAN.

### Comparison with CAN

#### Advantages of CAN over UART

1. **Robust Error Handling**: 
   - CAN has sophisticated error detection and handling mechanisms, including CRC, acknowledgment, and bit monitoring.
   - It can automatically retransmit corrupted messages, ensuring data integrity.

2. **Multi-Master and Multi-Node Support**: 
   - CAN allows multiple nodes to communicate on the same bus, with built-in arbitration to handle message priority.
   - UART is typically limited to point-to-point communication without additional hardware.

3. **Noise Immunity**:
   - CAN uses differential signaling, which provides excellent noise immunity, making it suitable for noisy environments like automotive and industrial applications.
   - UART's single-ended signaling is more susceptible to noise.

4. **Real-Time Capabilities**:
   - CAN’s message priority and arbitration make it suitable for real-time applications, ensuring critical messages get through first.

#### Disadvantages of CAN compared to UART

1. **Complexity**:
   - CAN is more complex to implement and requires more sophisticated hardware.
   - UART is simpler and easier to set up.

2. **Cost**:
   - CAN transceivers and controllers can be more expensive compared to the basic UART hardware.

3. **Speed**:
   - While CAN is efficient for its intended applications, UART can achieve higher data rates in simpler, low-noise environments (e.g., up to 10 Mbps with UART compared to typical maximums around 1 Mbps for CAN).

### Summary
**UART**:
- Simple and cost-effective for point-to-point communication.
- Limited error handling, distance, and speed capabilities.
- Easy to implement and widely available.

**CAN**:
- Robust, reliable, and ideal for multi-node communication in noisy environments.
- Complex and more expensive, but with superior error handling and real-time capabilities.



### CONCLUSION
So overall CAN is a better choice. 
***(1)*** Since our rover is a multi-master setup(and not a typical master-slave setup) and in such configurations CAN is the best choice.

***(2)*** On the rover there will be a stream of inputs/feedbacks going to the JETSON, but we need to prioritize them according to our needs(i.e some Arbitration is needed). This can only be implemented by CAN.

***(3)*** Also we need a protocol immune to the noise/EMI from other factors.

***(4)*** We need inbuilt error handling feature of CAN.