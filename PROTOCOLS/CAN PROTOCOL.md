Controller Area Network (CAN) is a robust vehicle bus standard designed to enable microcontrollers and devices to communicate with each other in applications without a host computer. It is widely used in automotive, industrial, and other embedded systems.
### Basic Principles
1. **Bus Topology**: CAN uses a bus topology, meaning all nodes (devices or microcontrollers) are connected to a single pair of twisted wires (CAN_H and CAN_L). These wires provide [[differential signaling]] to reduce noise and allow for long cable runs.
 ![[Pasted image 20240624172348.png]]

2. **Message-Based Protocol**: CAN is message-based, not address-based(SPI and I2C). Each message has a unique identifier, which determines the priority of the message.

3. **Multi-Master Capability**: Any node can transmit a message when the bus is free. If two or more nodes try to send a message simultaneously, the one with the highest priority (lowest identifier value) will continue, and the others will wait.

### Communication Process
1. **Frame Structure**: CAN messages are structured in frames. The primary frame types are:
   - **Data Frame**: Carries data from a transmitter to receivers.
   - **Remote Frame**: Requests data from a node.
   - **Error Frame**: Signals errors detected on the bus.
   - **Overload Frame**: Provides extra time for processing.

   A typical Data Frame includes:
   - **Identifier**: A unique identifier for the message.
   - **Control Field**: Indicates data length and other control information.
   - **Data Field**: The actual data being transmitted (0 to 8 bytes).
   - **CRC Field**: A cyclic redundancy check for error detection.
   - **ACK Field**: Acknowledgment from receivers.
   - **End-of-Frame (EOF)**: Marks the end of the frame.

2. **Arbitration**: When multiple nodes attempt to transmit simultaneously, CAN uses a non-destructive bitwise arbitration method based on the message identifiers. Each node monitors the bus and transmits its identifier bit-by-bit. If a node sees a dominant bit (0) when it has transmitted a recessive bit (1), it stops transmitting. This ensures that the message with the highest priority (lowest identifier) gets through without collision.

3. **Error Handling**: CAN has sophisticated error detection and handling mechanisms:
   - **Bit Errors**: Detected by nodes by monitoring the bus.
   - **Frame Check**: Ensures the correct format.
   - **Acknowledgment Errors**: Detected when a transmitted frame is not acknowledged.
   - **CRC Errors**: Detected using the CRC field.
   - **Form Errors**: Detected when a fixed format field contains illegal values.

   When an error is detected, the node sends an error frame, and the message is retransmitted. Nodes also keep track of errors using error counters, entering an error passive state if the count exceeds certain thresholds, and eventually going to a bus-off state if errors persist.

4. **Message Filtering and Acceptance**: Each node can be configured to receive specific messages based on identifiers, which allows efficient filtering and reduces the processing load on the microcontroller.
5.  **Bit Timing and Synchronization**:
    - CAN uses a method called "bit stuffing" and "bit timing" to maintain synchronization between nodes.
    - The bus state (recessive or dominant) is monitored continuously, and nodes adjust their internal clocks to stay in sync based on the edges of the bits transmitted on the bus.
- **Bit Stuffing**:
    
    - To ensure there are enough transitions for synchronization, CAN uses bit stuffing. After five consecutive bits of the same polarity, a bit of the opposite polarity is inserted. This helps receivers stay synchronized by providing regular edges to lock onto.
    ### How Asynchronous CAN Communication Works:

1. **Transmission**:
    
    - A node wanting to transmit waits until the bus is idle.
    - It starts transmitting its message frame, which includes the identifier, control bits, data, and error-checking bits.
2. **Reception**:
    
    - Receiving nodes detect the start of the message by identifying the start of frame (SOF) bit.
    - They then read the incoming bits, using bit transitions to maintain synchronization.


### CAN Protocol Versions
1. **CAN 2.0**: This version includes two parts:
   - **CAN 2.0A**: Uses 11-bit identifiers.
   - **CAN 2.0B**: Extends the identifier to 29 bits.

2. **CAN FD (Flexible Data-rate)**: Introduced to support higher data rates and larger data payloads (up to 64 bytes).

### Use Cases and Applications
- **Automotive**: Engine control units (ECUs), sensors, and other in-vehicle communication.
- **Industrial Automation**: Machinery, robotics, and control systems.
- **Medical Equipment**: Communication between various medical devices.
- **Aerospace**: Systems requiring high reliability and real-time data exchange.

### Advantages of CAN
- **Reliability**: Robust error detection and handling.
- **Efficiency**: Priority-based message arbitration and compact message format.
- **Scalability**: Easily add or remove nodes without significant changes to the network.
- **Noise Immunity**: Differential signaling reduces susceptibility to noise.

In summary, CAN is a highly reliable and efficient communication protocol designed for real-time data exchange in embedded systems. Its robustness and flexibility make it suitable for a wide range of applications, particularly in environments where reliability and real-time performance are critical.