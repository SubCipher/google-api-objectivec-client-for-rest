// NOTE: This file was generated by the ServiceGenerator.

// ----------------------------------------------------------------------------
// API:
//   Google Cloud RuntimeConfig API (runtimeconfig/v1beta1)
// Description:
//   Provides capabilities for dynamic configuration and coordination for
//   applications running on Google Cloud Platform.
// Documentation:
//   https://cloud.google.com/deployment-manager/docs/

#if GTLR_BUILT_AS_FRAMEWORK
  #import "GTLR/GTLRObject.h"
#else
  #import "GTLRObject.h"
#endif

#if GTLR_RUNTIME_VERSION != 3000
#error This file was generated by a different version of ServiceGenerator which is incompatible with this GTLR library source.
#endif

@class GTLRCloudRuntimeConfig_Cardinality;
@class GTLRCloudRuntimeConfig_EndCondition;
@class GTLRCloudRuntimeConfig_OperationMetadata;
@class GTLRCloudRuntimeConfig_OperationResponse;
@class GTLRCloudRuntimeConfig_RuntimeConfig;
@class GTLRCloudRuntimeConfig_Status;
@class GTLRCloudRuntimeConfig_StatusDetailsItem;
@class GTLRCloudRuntimeConfig_Variable;
@class GTLRCloudRuntimeConfig_Waiter;

NS_ASSUME_NONNULL_BEGIN

// ----------------------------------------------------------------------------
// Constants - For some of the classes' properties below.

// ----------------------------------------------------------------------------
// GTLRCloudRuntimeConfig_Variable.state

/**
 *  Variable had been deleted, while watch was executing.
 *
 *  Value: "DELETED"
 */
GTLR_EXTERN NSString * const kGTLRCloudRuntimeConfig_Variable_State_Deleted;
/**
 *  Variable had been updated, while watch was executing.
 *
 *  Value: "UPDATED"
 */
GTLR_EXTERN NSString * const kGTLRCloudRuntimeConfig_Variable_State_Updated;
/**
 *  Default variable state.
 *
 *  Value: "VARIABLE_STATE_UNSPECIFIED"
 */
GTLR_EXTERN NSString * const kGTLRCloudRuntimeConfig_Variable_State_VariableStateUnspecified;

/**
 *  The Cardinality condition is met when the count of `Variable` resources
 *  under the specified path prefix reaches the specified number.
 *  For example, take the following variables in a RuntimeConfig object:
 *  /foo/variable1 = "value1"
 *  /foo/variable2 = "value2"
 *  /bar/variable3 = "value3"
 *  These variables would satisfy a Cardinality condition with `path` set to
 *  "/foo" and `number` set to 2, but would not satisify the same condition
 *  with `number` set to 3.
 */
@interface GTLRCloudRuntimeConfig_Cardinality : GTLRObject

/**
 *  The number of decendents of `path` that must exist before this condition
 *  is met. Optional; defaults to 1 if not specified.
 *
 *  Uses NSNumber of intValue.
 */
@property(strong, nullable) NSNumber *number;

/** The root of the variable subtree to monitor. Required. */
@property(copy, nullable) NSString *path;

@end


/**
 *  A generic empty message that you can re-use to avoid defining duplicated
 *  empty messages in your APIs. A typical example is to use it as the request
 *  or the response type of an API method. For instance:
 *  service Foo {
 *  rpc Bar(google.protobuf.Empty) returns (google.protobuf.Empty);
 *  }
 *  The JSON representation for `Empty` is empty JSON object `{}`.
 */
@interface GTLRCloudRuntimeConfig_Empty : GTLRObject
@end


/**
 *  A condition that a Waiter resource is waiting for. The set of possible
 *  conditions may expand over time.
 */
@interface GTLRCloudRuntimeConfig_EndCondition : GTLRObject

/** The Cardinality condition type configuration. */
@property(strong, nullable) GTLRCloudRuntimeConfig_Cardinality *cardinality;

@end


/**
 *  Response for the `ListConfigs()` method.
 *  Order of returned configuration objects is arbitrary.
 *
 *  @note This class supports NSFastEnumeration and indexed subscripting over
 *        its "configs" property. If returned as the result of a query, it
 *        should support automatic pagination (when @c shouldFetchNextPages is
 *        enabled).
 */
@interface GTLRCloudRuntimeConfig_ListConfigsResponse : GTLRCollectionObject

/**
 *  Found configurations in the project.
 *
 *  @note This property is used to support NSFastEnumeration and indexed
 *        subscripting on this class.
 */
@property(strong, nullable) NSArray<GTLRCloudRuntimeConfig_RuntimeConfig *> *configs;

/** Pagination support. */
@property(copy, nullable) NSString *nextPageToken;

@end


/**
 *  Response for the `ListVariables()` method.
 *  Order of returned variable objects is arbitrary.
 *
 *  @note This class supports NSFastEnumeration and indexed subscripting over
 *        its "variables" property. If returned as the result of a query, it
 *        should support automatic pagination (when @c shouldFetchNextPages is
 *        enabled).
 */
@interface GTLRCloudRuntimeConfig_ListVariablesResponse : GTLRCollectionObject

/** Pagination support. */
@property(copy, nullable) NSString *nextPageToken;

/**
 *  Matched variables and their values.
 *
 *  @note This property is used to support NSFastEnumeration and indexed
 *        subscripting on this class.
 */
@property(strong, nullable) NSArray<GTLRCloudRuntimeConfig_Variable *> *variables;

@end


/**
 *  Response for the `ListWaiters()` method.
 *  Order of returned waiter objects is arbitrary.
 *
 *  @note This class supports NSFastEnumeration and indexed subscripting over
 *        its "waiters" property. If returned as the result of a query, it
 *        should support automatic pagination (when @c shouldFetchNextPages is
 *        enabled).
 */
@interface GTLRCloudRuntimeConfig_ListWaitersResponse : GTLRCollectionObject

/** Pagination support. */
@property(copy, nullable) NSString *nextPageToken;

/**
 *  Found waiters in the project.
 *
 *  @note This property is used to support NSFastEnumeration and indexed
 *        subscripting on this class.
 */
@property(strong, nullable) NSArray<GTLRCloudRuntimeConfig_Waiter *> *waiters;

@end


/**
 *  This resource represents a long-running operation that is the result of a
 *  network API call.
 */
@interface GTLRCloudRuntimeConfig_Operation : GTLRObject

/**
 *  If the value is `false`, it means the operation is still in progress.
 *  If true, the operation is completed, and either `error` or `response` is
 *  available.
 *
 *  Uses NSNumber of boolValue.
 */
@property(strong, nullable) NSNumber *done;

/** The error result of the operation in case of failure. */
@property(strong, nullable) GTLRCloudRuntimeConfig_Status *error;

/**
 *  Service-specific metadata associated with the operation. It typically
 *  contains progress information and common metadata such as create time.
 *  Some services might not provide such metadata. Any method that returns a
 *  long-running operation should document the metadata type, if any.
 */
@property(strong, nullable) GTLRCloudRuntimeConfig_OperationMetadata *metadata;

/**
 *  The server-assigned name, which is only unique within the same service that
 *  originally returns it. If you use the default HTTP mapping, the
 *  `name` should have the format of `operations/some/unique/name`.
 */
@property(copy, nullable) NSString *name;

/**
 *  The normal response of the operation in case of success. If the original
 *  method returns no data on success, such as `Delete`, the response is
 *  `google.protobuf.Empty`. If the original method is standard
 *  `Get`/`Create`/`Update`, the response should be the resource. For other
 *  methods, the response should have the type `XxxResponse`, where `Xxx`
 *  is the original method name. For example, if the original method name
 *  is `TakeSnapshot()`, the inferred response type is
 *  `TakeSnapshotResponse`.
 */
@property(strong, nullable) GTLRCloudRuntimeConfig_OperationResponse *response;

@end


/**
 *  Service-specific metadata associated with the operation. It typically
 *  contains progress information and common metadata such as create time.
 *  Some services might not provide such metadata. Any method that returns a
 *  long-running operation should document the metadata type, if any.
 *
 *  @note This class is documented as having more properties of any valid JSON
 *        type. Use @c -additionalJSONKeys and @c -additionalPropertyForName: to
 *        get the list of properties and then fetch them; or @c
 *        -additionalProperties to fetch them all at once.
 */
@interface GTLRCloudRuntimeConfig_OperationMetadata : GTLRObject
@end


/**
 *  The normal response of the operation in case of success. If the original
 *  method returns no data on success, such as `Delete`, the response is
 *  `google.protobuf.Empty`. If the original method is standard
 *  `Get`/`Create`/`Update`, the response should be the resource. For other
 *  methods, the response should have the type `XxxResponse`, where `Xxx`
 *  is the original method name. For example, if the original method name
 *  is `TakeSnapshot()`, the inferred response type is
 *  `TakeSnapshotResponse`.
 *
 *  @note This class is documented as having more properties of any valid JSON
 *        type. Use @c -additionalJSONKeys and @c -additionalPropertyForName: to
 *        get the list of properties and then fetch them; or @c
 *        -additionalProperties to fetch them all at once.
 */
@interface GTLRCloudRuntimeConfig_OperationResponse : GTLRObject
@end


/**
 *  RuntimeConfig is the primary resource in the Configuration service.
 *  It consists of metadata and a hierarchy of variables.
 */
@interface GTLRCloudRuntimeConfig_RuntimeConfig : GTLRObject

/**
 *  Description of the configuration object.
 *  `len(description)` must be less than 256.
 *
 *  Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
 */
@property(copy, nullable) NSString *descriptionProperty;

/**
 *  The resource name of a runtime config.
 *  It has the format of "projects/{project_id}/configs/{config_id}",
 *  where `project_id` is a valid Google cloud project ID, and the
 *  `config_id` must match RFC 1035 segment specification, and
 *  `len(config_id)` must be less than 64 bytes.
 *  The name is assigned by the client, but will be validated on the server
 *  side to adhere to the format.
 *  Name is immutable and cannot be changed.
 */
@property(copy, nullable) NSString *name;

@end


/**
 *  The `Status` type defines a logical error model that is suitable for
 *  different
 *  programming environments, including REST APIs and RPC APIs. It is used by
 *  [gRPC](https://github.com/grpc). The error model is designed to be:
 *  - Simple to use and understand for most users
 *  - Flexible enough to meet unexpected needs
 *  # Overview
 *  The `Status` message contains three pieces of data: error code, error
 *  message,
 *  and error details. The error code should be an enum value of
 *  google.rpc.Code, but it may accept additional error codes if needed. The
 *  error message should be a developer-facing English message that helps
 *  developers *understand* and *resolve* the error. If a localized user-facing
 *  error message is needed, put the localized message in the error details or
 *  localize it in the client. The optional error details may contain arbitrary
 *  information about the error. There is a predefined set of error detail types
 *  in the package `google.rpc` which can be used for common error conditions.
 *  # Language mapping
 *  The `Status` message is the logical representation of the error model, but
 *  it
 *  is not necessarily the actual wire format. When the `Status` message is
 *  exposed in different client libraries and different wire protocols, it can
 *  be
 *  mapped differently. For example, it will likely be mapped to some exceptions
 *  in Java, but more likely mapped to some error codes in C.
 *  # Other uses
 *  The error model and the `Status` message can be used in a variety of
 *  environments, either with or without APIs, to provide a
 *  consistent developer experience across different environments.
 *  Example uses of this error model include:
 *  - Partial errors. If a service needs to return partial errors to the client,
 *  it may embed the `Status` in the normal response to indicate the partial
 *  errors.
 *  - Workflow errors. A typical workflow has multiple steps. Each step may
 *  have a `Status` message for error reporting purpose.
 *  - Batch operations. If a client uses batch request and batch response, the
 *  `Status` message should be used directly inside batch response, one for
 *  each error sub-response.
 *  - Asynchronous operations. If an API call embeds asynchronous operation
 *  results in its response, the status of those operations should be
 *  represented directly using the `Status` message.
 *  - Logging. If some API errors are stored in logs, the message `Status` could
 *  be used directly after any stripping needed for security/privacy reasons.
 */
@interface GTLRCloudRuntimeConfig_Status : GTLRObject

/**
 *  The status code, which should be an enum value of google.rpc.Code.
 *
 *  Uses NSNumber of intValue.
 */
@property(strong, nullable) NSNumber *code;

/**
 *  A list of messages that carry the error details. There will be a
 *  common set of message types for APIs to use.
 */
@property(strong, nullable) NSArray<GTLRCloudRuntimeConfig_StatusDetailsItem *> *details;

/**
 *  A developer-facing error message, which should be in English. Any
 *  user-facing error message should be localized and sent in the
 *  google.rpc.Status.details field, or localized by the client.
 */
@property(copy, nullable) NSString *message;

@end


/**
 *  GTLRCloudRuntimeConfig_StatusDetailsItem
 *
 *  @note This class is documented as having more properties of any valid JSON
 *        type. Use @c -additionalJSONKeys and @c -additionalPropertyForName: to
 *        get the list of properties and then fetch them; or @c
 *        -additionalProperties to fetch them all at once.
 */
@interface GTLRCloudRuntimeConfig_StatusDetailsItem : GTLRObject
@end


/**
 *  Variable message describes a single variable within a Configuration object.
 *  name denotes the hierarchical variable name, e.g.
 *  ports/serving_port within flags configuration object.
 *  Value is an opaque string and only leaf variables can have values.
 */
@interface GTLRCloudRuntimeConfig_Variable : GTLRObject

/**
 *  Name of the variable resource.
 *  It has format of
 *  "projects/{project_id}/configs/{config_id}/variables/{variable_id}",
 *  Where `project_id` must be a valid Google Cloud project ID, `config_id`
 *  must be a valid RuntimeConfig object and `variable_id` follows Unix
 *  file system file path naming.
 *  `variable_id` can contain ASCII letters, numbers, slashes and dashes.
 *  Slashes are used as path element separators and are not part of the
 *  `variable_id` itself, so `variable_id` must contain at least one non-slash
 *  character. Multiple slashes are coalesced into single slash character.
 *  Each path segment should follow RFC 1035 segment specification.
 *  `len(variable_id)` must be less than 256 bytes.
 *  The name is assigned by the client, but will be validated on the server
 *  side to adhere to the format.
 *  Name is immutable and cannot be changed.
 */
@property(copy, nullable) NSString *name;

/**
 *  [Ouput only] The current state of the variable.
 *  State denotes the outcome of the Watch call and is unset by the Get/List
 *  calls.
 *
 *  Likely values:
 *    @arg @c kGTLRCloudRuntimeConfig_Variable_State_Deleted Variable had been
 *        deleted, while watch was executing. (Value: "DELETED")
 *    @arg @c kGTLRCloudRuntimeConfig_Variable_State_Updated Variable had been
 *        updated, while watch was executing. (Value: "UPDATED")
 *    @arg @c kGTLRCloudRuntimeConfig_Variable_State_VariableStateUnspecified
 *        Default variable state. (Value: "VARIABLE_STATE_UNSPECIFIED")
 */
@property(copy, nullable) NSString *state;

/** [Output Only] The time of the last variable update. */
@property(strong, nullable) GTLRDateTime *updateTime;

/**
 *  `len(value)` must be less than 4096 bytes. Empty values are also accepted.
 *  value must be Base64 encoded.
 *
 *  Contains encoded binary data; GTLRBase64 can encode/decode (probably
 *  web-safe format).
 */
@property(copy, nullable) NSString *value;

@end


/**
 *  A Waiter resource waits for some condition within a RuntimeConfig resource
 *  to be met. For example: each node in a distributed system startup process
 *  writes a value to a Variable resource indicating its readiness. A Waiter
 *  configured with the proper `success` condition can be used to wait until
 *  some number of nodes have checked in.
 *  Once created, a Waiter resource is immutable.
 */
@interface GTLRCloudRuntimeConfig_Waiter : GTLRObject

/**
 *  The instant at which this Waiter was created. Adding the value of `timeout`
 *  to this instant yields the timeout deadline for this Waiter. Output only.
 */
@property(strong, nullable) GTLRDateTime *createTime;

/**
 *  If the value is `false`, it means the Waiter is still waiting for one of
 *  its conditions to be met.
 *  If true, the Waiter has finished. If the Waiter finished due to a timeout
 *  or failure, `error` will be set. Output only.
 *
 *  Uses NSNumber of boolValue.
 */
@property(strong, nullable) NSNumber *done;

/**
 *  If the Waiter ended due to a failure or timeout, this value will be set.
 *  Output only.
 */
@property(strong, nullable) GTLRCloudRuntimeConfig_Status *error;

/**
 *  The failure condition. If this condition is met, `done` will be set to
 *  `true` and the `error` code will be set to ABORTED. The failure condition
 *  takes precedence over the success condition. If both conditions are met, a
 *  failure will be indicated. This value is optional; if no failure condition
 *  is set, the only failure scenario will be a timeout. Optional.
 */
@property(strong, nullable) GTLRCloudRuntimeConfig_EndCondition *failure;

/**
 *  Name of the variable resource.
 *  It has format of
 *  "projects/{project_id}/configs/{config_id}/waiters/{waiter_id}",
 *  Where `project_id` must be a valid Google Cloud project ID, `config_id`
 *  must be a valid RuntimeConfig object and the `waiter_id` must match
 *  RFC 1035 segment specification, and `len(waiter_id)` must be less than
 *  64 bytes.
 *  The name is assigned by the client, but will be validated on the server
 *  side to adhere to the format.
 *  Name is immutable and cannot be changed. Required.
 */
@property(copy, nullable) NSString *name;

/**
 *  The success condition. If this condition is met, `done` will be set to
 *  `true` and the `error` value will remain unset. The failure condition
 *  takes precedence over the success condition. If both conditions are met, a
 *  failure will be indicated. Required.
 */
@property(strong, nullable) GTLRCloudRuntimeConfig_EndCondition *success;

/**
 *  The timeout, beginning from the instant that CreateWaiter is called. If
 *  this timeout elapses prior to the success or failure conditions being met,
 *  the Waiter will fail and the `error` code will be set to DEADLINE_EXCEEDED.
 *  Required.
 *
 *  String format is #.###s (seconds).
 */
@property(copy, nullable) NSString *timeout;

@end


/**
 *  Request for the `WatchVariable()` method.
 */
@interface GTLRCloudRuntimeConfig_WatchVariableRequest : GTLRObject

/**
 *  If backend has a variable that has a newer value than this timestamp, then
 *  request will return immediately with current value.
 *  If not specified or variable has an older timestamp, will wait for the new
 *  value.
 */
@property(strong, nullable) GTLRDateTime *newerThan;

@end

NS_ASSUME_NONNULL_END
