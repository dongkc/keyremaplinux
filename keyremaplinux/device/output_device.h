#ifndef KEYREMAPLINUX_DEVICE_OUTPUT_DEVICE
#define KEYREMAPLINUX_DEVICE_OUTPUT_DEVICE

#include <string>

namespace keyremaplinux {
  
using namespace std;

class OutputDevice {
public:
  OutputDevice();

  virtual ~OutputDevice();

  void WriteInputEvent(input_event event);

  // Outputs event that signals end of output chunk.
  void WriteSyncEvent();

private:
  static string FindUInputDevice();
  
  void EnableUInputEvents();

  void CreateDeviceFromUInput();

  string outputPath_ = "";

  // Descriptor of device we are writing to
  int outputDescriptor_ = 0;

  OutputDevice(const OutputDevice& daemon) = delete;

  void operator=(const OutputDevice&) = delete;

};

}  // end namespace keyremaplinux

#endif  // KEYREMAPLINUX_DEVICE_OUTPUT_DEVICE