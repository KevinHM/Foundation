// CFFileDescriptor.h

#include <CoreFoundation/CFRunLoop.h>

__BEGIN_DECLS

typedef int CFFileDescriptorNativeDescriptor;
typedef struct __CFFileDescriptor * CFFileDescriptorRef;
enum {
    kCFFileDescriptorReadCallBack = 1UL << 0,
    kCFFileDescriptorWriteCallBack = 1UL << 1
};
typedef void (*CFFileDescriptorCallBack)(CFFileDescriptorRef f, CFOptionFlags callBackTypes, void *info);
typedef struct {
    CFIndex version;
    void *  info;
    void *  (*retain)(void *info);
    void    (*release)(void *info);
    CFStringRef (*copyDescription)(void *info);
} CFFileDescriptorContext;

CF_EXPORT CFFileDescriptorRef               CFFileDescriptorCreate(CFAllocatorRef allocator, CFFileDescriptorNativeDescriptor fd, Boolean closeOnInvalidate, CFFileDescriptorCallBack callout, const CFFileDescriptorContext *context);
CF_EXPORT CFTypeID                          CFFileDescriptorGetTypeID(void);
CF_EXPORT CFFileDescriptorNativeDescriptor  CFFileDescriptorGetNativeDescriptor(CFFileDescriptorRef f);
CF_EXPORT void                              CFFileDescriptorGetContext(CFFileDescriptorRef f, CFFileDescriptorContext *context);
CF_EXPORT void                              CFFileDescriptorEnableCallBacks(CFFileDescriptorRef f, CFOptionFlags callBackTypes);
CF_EXPORT void                              CFFileDescriptorDisableCallBacks(CFFileDescriptorRef f, CFOptionFlags callBackTypes);
CF_EXPORT void                              CFFileDescriptorInvalidate(CFFileDescriptorRef f);
CF_EXPORT Boolean                           CFFileDescriptorIsValid(CFFileDescriptorRef f);
CF_EXPORT CFRunLoopSourceRef                CFFileDescriptorCreateRunLoopSource(CFAllocatorRef allocator, CFFileDescriptorRef f, CFIndex order);

__END_DECLS
