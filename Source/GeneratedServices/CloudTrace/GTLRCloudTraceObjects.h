// NOTE: This file was generated by the ServiceGenerator.

// ----------------------------------------------------------------------------
// API:
//   Stackdriver Trace API (cloudtrace/v1)
// Description:
//   Send and retrieve trace data from Stackdriver Trace. Data is generated and
//   available by default for all App Engine applications. Data from other
//   applications can be written to Stackdriver Trace for display, reporting,
//   and analysis.
// Documentation:
//   https://cloud.google.com/trace

#if GTLR_BUILT_AS_FRAMEWORK
  #import "GTLR/GTLRObject.h"
#else
  #import "GTLRObject.h"
#endif

#if GTLR_RUNTIME_VERSION != 3000
#error This file was generated by a different version of ServiceGenerator which is incompatible with this GTLR library source.
#endif

@class GTLRCloudTrace_Trace;
@class GTLRCloudTrace_TraceSpan;
@class GTLRCloudTrace_TraceSpan_Labels;

NS_ASSUME_NONNULL_BEGIN

// ----------------------------------------------------------------------------
// Constants - For some of the classes' properties below.

// ----------------------------------------------------------------------------
// GTLRCloudTrace_TraceSpan.kind

/**
 *  Indicates that the span covers the client-side wrapper around an RPC or
 *  other remote request.
 *
 *  Value: "RPC_CLIENT"
 */
GTLR_EXTERN NSString * const kGTLRCloudTrace_TraceSpan_Kind_RpcClient;
/**
 *  Indicates that the span covers server-side handling of an RPC or other
 *  remote network request.
 *
 *  Value: "RPC_SERVER"
 */
GTLR_EXTERN NSString * const kGTLRCloudTrace_TraceSpan_Kind_RpcServer;
/**
 *  Unspecified.
 *
 *  Value: "SPAN_KIND_UNSPECIFIED"
 */
GTLR_EXTERN NSString * const kGTLRCloudTrace_TraceSpan_Kind_SpanKindUnspecified;

/**
 *  A generic empty message that you can re-use to avoid defining duplicated
 *  empty messages in your APIs. A typical example is to use it as the request
 *  or the response type of an API method. For instance:
 *  service Foo {
 *  rpc Bar(google.protobuf.Empty) returns (google.protobuf.Empty);
 *  }
 *  The JSON representation for `Empty` is empty JSON object `{}`.
 */
@interface GTLRCloudTrace_Empty : GTLRObject
@end


/**
 *  The response message for the `ListTraces` method.
 *
 *  @note This class supports NSFastEnumeration and indexed subscripting over
 *        its "traces" property. If returned as the result of a query, it should
 *        support automatic pagination (when @c shouldFetchNextPages is
 *        enabled).
 */
@interface GTLRCloudTrace_ListTracesResponse : GTLRCollectionObject

/**
 *  If defined, indicates that there are more traces that match the request
 *  and that this value should be passed to the next request to continue
 *  retrieving additional traces.
 */
@property(nonatomic, copy, nullable) NSString *nextPageToken;

/**
 *  List of trace records returned.
 *
 *  @note This property is used to support NSFastEnumeration and indexed
 *        subscripting on this class.
 */
@property(nonatomic, strong, nullable) NSArray<GTLRCloudTrace_Trace *> *traces;

@end


/**
 *  A trace describes how long it takes for an application to perform an
 *  operation. It consists of a set of spans, each of which represent a single
 *  timed event within the operation.
 */
@interface GTLRCloudTrace_Trace : GTLRObject

/** Project ID of the Cloud project where the trace data is stored. */
@property(nonatomic, copy, nullable) NSString *projectId;

/** Collection of spans in the trace. */
@property(nonatomic, strong, nullable) NSArray<GTLRCloudTrace_TraceSpan *> *spans;

/**
 *  Globally unique identifier for the trace. This identifier is a 128-bit
 *  numeric value formatted as a 32-byte hex string.
 */
@property(nonatomic, copy, nullable) NSString *traceId;

@end


/**
 *  List of new or updated traces.
 */
@interface GTLRCloudTrace_Traces : GTLRObject

/** List of traces. */
@property(nonatomic, strong, nullable) NSArray<GTLRCloudTrace_Trace *> *traces;

@end


/**
 *  A span represents a single timed event within a trace. Spans can be nested
 *  and form a trace tree. Often, a trace contains a root span that describes
 *  the
 *  end-to-end latency of an operation and, optionally, one or more subspans for
 *  its suboperations. Spans do not need to be contiguous. There may be gaps
 *  between spans in a trace.
 */
@interface GTLRCloudTrace_TraceSpan : GTLRObject

/** End time of the span in nanoseconds from the UNIX epoch. */
@property(nonatomic, strong, nullable) GTLRDateTime *endTime;

/**
 *  Distinguishes between spans generated in a particular context. For example,
 *  two spans with the same name may be distinguished using `RPC_CLIENT`
 *  and `RPC_SERVER` to identify queueing latency associated with the span.
 *
 *  Likely values:
 *    @arg @c kGTLRCloudTrace_TraceSpan_Kind_RpcClient Indicates that the span
 *        covers the client-side wrapper around an RPC or
 *        other remote request. (Value: "RPC_CLIENT")
 *    @arg @c kGTLRCloudTrace_TraceSpan_Kind_RpcServer Indicates that the span
 *        covers server-side handling of an RPC or other
 *        remote network request. (Value: "RPC_SERVER")
 *    @arg @c kGTLRCloudTrace_TraceSpan_Kind_SpanKindUnspecified Unspecified.
 *        (Value: "SPAN_KIND_UNSPECIFIED")
 */
@property(nonatomic, copy, nullable) NSString *kind;

/**
 *  Collection of labels associated with the span. Label keys must be less than
 *  128 bytes. Label values must be less than 16 kilobytes (10MB for
 *  `/stacktrace` values).
 *  Some predefined label keys exist, or you may create your own. When creating
 *  your own, we recommend the following formats:
 *  * `/category/product/key` for agents of well-known products (e.g.
 *  `/db/mongodb/read_size`).
 *  * `short_host/path/key` for domain-specific keys (e.g.
 *  `foo.com/myproduct/bar`)
 *  Predefined labels include:
 *  * `/agent`
 *  * `/component`
 *  * `/error/message`
 *  * `/error/name`
 *  * `/http/client_city`
 *  * `/http/client_country`
 *  * `/http/client_protocol`
 *  * `/http/client_region`
 *  * `/http/host`
 *  * `/http/method`
 *  * `/http/redirected_url`
 *  * `/http/request/size`
 *  * `/http/response/size`
 *  * `/http/status_code`
 *  * `/http/url`
 *  * `/http/user_agent`
 *  * `/pid`
 *  * `/stacktrace`
 *  * `/tid`
 */
@property(nonatomic, strong, nullable) GTLRCloudTrace_TraceSpan_Labels *labels;

/**
 *  Name of the span. Must be less than 128 bytes. The span name is sanitized
 *  and displayed in the Stackdriver Trace tool in the
 *  {% dynamic print site_values.console_name %}.
 *  The name may be a method name or some other per-call site name.
 *  For the same executable and the same call point, a best practice is
 *  to use a consistent name, which makes it easier to correlate
 *  cross-trace spans.
 */
@property(nonatomic, copy, nullable) NSString *name;

/**
 *  ID of the parent span, if any. Optional.
 *
 *  Uses NSNumber of unsignedLongLongValue.
 */
@property(nonatomic, strong, nullable) NSNumber *parentSpanId;

/**
 *  Identifier for the span. Must be a 64-bit integer other than 0 and
 *  unique within a trace.
 *
 *  Uses NSNumber of unsignedLongLongValue.
 */
@property(nonatomic, strong, nullable) NSNumber *spanId;

/** Start time of the span in nanoseconds from the UNIX epoch. */
@property(nonatomic, strong, nullable) GTLRDateTime *startTime;

@end


/**
 *  Collection of labels associated with the span. Label keys must be less than
 *  128 bytes. Label values must be less than 16 kilobytes (10MB for
 *  `/stacktrace` values).
 *  Some predefined label keys exist, or you may create your own. When creating
 *  your own, we recommend the following formats:
 *  * `/category/product/key` for agents of well-known products (e.g.
 *  `/db/mongodb/read_size`).
 *  * `short_host/path/key` for domain-specific keys (e.g.
 *  `foo.com/myproduct/bar`)
 *  Predefined labels include:
 *  * `/agent`
 *  * `/component`
 *  * `/error/message`
 *  * `/error/name`
 *  * `/http/client_city`
 *  * `/http/client_country`
 *  * `/http/client_protocol`
 *  * `/http/client_region`
 *  * `/http/host`
 *  * `/http/method`
 *  * `/http/redirected_url`
 *  * `/http/request/size`
 *  * `/http/response/size`
 *  * `/http/status_code`
 *  * `/http/url`
 *  * `/http/user_agent`
 *  * `/pid`
 *  * `/stacktrace`
 *  * `/tid`
 *
 *  @note This class is documented as having more properties of NSString. Use @c
 *        -additionalJSONKeys and @c -additionalPropertyForName: to get the list
 *        of properties and then fetch them; or @c -additionalProperties to
 *        fetch them all at once.
 */
@interface GTLRCloudTrace_TraceSpan_Labels : GTLRObject
@end

NS_ASSUME_NONNULL_END
