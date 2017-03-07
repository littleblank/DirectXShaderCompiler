//===-- InstBuilder.h - SPIR-V instruction builder --------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// AUTOMATICALLY GENERATED from the SPIR-V JSON grammar:
//   spirv.core.grammar.json.
// DO NOT MODIFY!

#ifndef LLVM_CLANG_SPIRV_INSTBUILDER_H
#define LLVM_CLANG_SPIRV_INSTBUILDER_H

#include <deque>
#include <functional>
#include <initializer_list>
#include <string>
#include <utility>
#include <vector>

#include "clang/SPIRV/Option.h"
#include "clang/SPIRV/spirv.hpp"

namespace clang {
namespace spirv {

class InstBuilder {
public:
  enum class Status : int32_t {
    Success = 0,
    NestedInst = -1,
    ZeroResultType = -2,
    ZeroResultId = -3,
    ExpectBuiltIn = -4,
    ExpectFPFastMathMode = -5,
    ExpectFPRoundingMode = -6,
    ExpectFunctionParameterAttribute = -7,
    ExpectIdRef = -8,
    ExpectLinkageType = -9,
    ExpectLiteralInteger = -10,
    ExpectLiteralString = -11
  };

  InstBuilder();

  // Finalizes the building.
  Status x(std::function<void(std::vector<uint32_t> &&)> consumer);
  // Clears the current instruction under building.
  void clear();

  // Instruction building methods.
  InstBuilder &opNop();
  InstBuilder &opUndef(uint32_t result_type, uint32_t result_id);
  InstBuilder &opSourceContinued(std::string continued_source);
  InstBuilder &opSource(spv::SourceLanguage source_language, uint32_t version,
                        Option<uint32_t> file, Option<std::string> source);
  InstBuilder &opSourceExtension(std::string extension);
  InstBuilder &opName(uint32_t target, std::string name);
  InstBuilder &opMemberName(uint32_t type, uint32_t member, std::string name);
  InstBuilder &opString(uint32_t result_id, std::string string);
  InstBuilder &opLine(uint32_t file, uint32_t line, uint32_t column);
  InstBuilder &opExtension(std::string name);
  InstBuilder &opExtInstImport(uint32_t result_id, std::string name);
  InstBuilder &opExtInst(uint32_t result_type, uint32_t result_id, uint32_t set,
                         uint32_t instruction,
                         std::initializer_list<uint32_t> operand_1_operand_2_);
  InstBuilder &opMemoryModel(spv::AddressingModel addressing_model,
                             spv::MemoryModel memory_model);
  InstBuilder &opEntryPoint(spv::ExecutionModel execution_model,
                            uint32_t entry_point, std::string name,
                            std::initializer_list<uint32_t> interface);
  InstBuilder &opExecutionMode(uint32_t entry_point, spv::ExecutionMode mode);
  InstBuilder &opCapability(spv::Capability capability);
  InstBuilder &opTypeVoid(uint32_t result_id);
  InstBuilder &opTypeBool(uint32_t result_id);
  InstBuilder &opTypeInt(uint32_t result_id, uint32_t width,
                         uint32_t signedness);
  InstBuilder &opTypeFloat(uint32_t result_id, uint32_t width);
  InstBuilder &opTypeVector(uint32_t result_id, uint32_t component_type,
                            uint32_t component_count);
  InstBuilder &opTypeMatrix(uint32_t result_id, uint32_t column_type,
                            uint32_t column_count);
  InstBuilder &opTypeImage(uint32_t result_id, uint32_t sampled_type,
                           spv::Dim dim, uint32_t depth, uint32_t arrayed,
                           uint32_t ms, uint32_t sampled,
                           spv::ImageFormat image_format,
                           Option<spv::AccessQualifier> access_qualifier);
  InstBuilder &opTypeSampler(uint32_t result_id);
  InstBuilder &opTypeSampledImage(uint32_t result_id, uint32_t image_type);
  InstBuilder &opTypeArray(uint32_t result_id, uint32_t element_type,
                           uint32_t length);
  InstBuilder &opTypeRuntimeArray(uint32_t result_id, uint32_t element_type);
  InstBuilder &
  opTypeStruct(uint32_t result_id,
               std::initializer_list<uint32_t> member_0_type_member_1_type_);
  InstBuilder &opTypeOpaque(uint32_t result_id,
                            std::string the_name_of_the_opaque_type);
  InstBuilder &opTypePointer(uint32_t result_id,
                             spv::StorageClass storage_class, uint32_t type);
  InstBuilder &opTypeFunction(
      uint32_t result_id, uint32_t return_type,
      std::initializer_list<uint32_t> parameter_0_type_parameter_1_type_);
  InstBuilder &opTypeEvent(uint32_t result_id);
  InstBuilder &opTypeDeviceEvent(uint32_t result_id);
  InstBuilder &opTypeReserveId(uint32_t result_id);
  InstBuilder &opTypeQueue(uint32_t result_id);
  InstBuilder &opTypePipe(uint32_t result_id, spv::AccessQualifier qualifier);
  InstBuilder &opTypeForwardPointer(uint32_t pointer_type,
                                    spv::StorageClass storage_class);
  InstBuilder &opConstantTrue(uint32_t result_type, uint32_t result_id);
  InstBuilder &opConstantFalse(uint32_t result_type, uint32_t result_id);
  InstBuilder &
  opConstantComposite(uint32_t result_type, uint32_t result_id,
                      std::initializer_list<uint32_t> constituents);
  InstBuilder &
  opConstantSampler(uint32_t result_type, uint32_t result_id,
                    spv::SamplerAddressingMode sampler_addressing_mode,
                    uint32_t param, spv::SamplerFilterMode sampler_filter_mode);
  InstBuilder &opConstantNull(uint32_t result_type, uint32_t result_id);
  InstBuilder &opSpecConstantTrue(uint32_t result_type, uint32_t result_id);
  InstBuilder &opSpecConstantFalse(uint32_t result_type, uint32_t result_id);
  InstBuilder &
  opSpecConstantComposite(uint32_t result_type, uint32_t result_id,
                          std::initializer_list<uint32_t> constituents);
  InstBuilder &opSpecConstantOp(uint32_t result_type, uint32_t result_id,
                                spv::Op opcode);
  InstBuilder &opFunction(uint32_t result_type, uint32_t result_id,
                          spv::FunctionControlMask function_control,
                          uint32_t function_type);
  InstBuilder &opFunctionParameter(uint32_t result_type, uint32_t result_id);
  InstBuilder &opFunctionEnd();
  InstBuilder &
  opFunctionCall(uint32_t result_type, uint32_t result_id, uint32_t function,
                 std::initializer_list<uint32_t> argument_0_argument_1_);
  InstBuilder &opVariable(uint32_t result_type, uint32_t result_id,
                          spv::StorageClass storage_class,
                          Option<uint32_t> initializer);
  InstBuilder &opImageTexelPointer(uint32_t result_type, uint32_t result_id,
                                   uint32_t image, uint32_t coordinate,
                                   uint32_t sample);
  InstBuilder &opLoad(uint32_t result_type, uint32_t result_id,
                      uint32_t pointer,
                      Option<spv::MemoryAccessMask> memory_access);
  InstBuilder &opStore(uint32_t pointer, uint32_t object,
                       Option<spv::MemoryAccessMask> memory_access);
  InstBuilder &opCopyMemory(uint32_t target, uint32_t source,
                            Option<spv::MemoryAccessMask> memory_access);
  InstBuilder &opCopyMemorySized(uint32_t target, uint32_t source,
                                 uint32_t size,
                                 Option<spv::MemoryAccessMask> memory_access);
  InstBuilder &opAccessChain(uint32_t result_type, uint32_t result_id,
                             uint32_t base,
                             std::initializer_list<uint32_t> indexes);
  InstBuilder &opInBoundsAccessChain(uint32_t result_type, uint32_t result_id,
                                     uint32_t base,
                                     std::initializer_list<uint32_t> indexes);
  InstBuilder &opPtrAccessChain(uint32_t result_type, uint32_t result_id,
                                uint32_t base, uint32_t element,
                                std::initializer_list<uint32_t> indexes);
  InstBuilder &opArrayLength(uint32_t result_type, uint32_t result_id,
                             uint32_t structure, uint32_t array_member);
  InstBuilder &opGenericPtrMemSemantics(uint32_t result_type,
                                        uint32_t result_id, uint32_t pointer);
  InstBuilder &
  opInBoundsPtrAccessChain(uint32_t result_type, uint32_t result_id,
                           uint32_t base, uint32_t element,
                           std::initializer_list<uint32_t> indexes);
  InstBuilder &opDecorate(uint32_t target, spv::Decoration decoration);
  InstBuilder &opMemberDecorate(uint32_t structure_type, uint32_t member,
                                spv::Decoration decoration);
  InstBuilder &opDecorationGroup(uint32_t result_id);
  InstBuilder &opGroupDecorate(uint32_t decoration_group,
                               std::initializer_list<uint32_t> targets);
  InstBuilder &opGroupMemberDecorate(
      uint32_t decoration_group,
      std::initializer_list<std::pair<uint32_t, uint32_t>> targets);
  InstBuilder &opVectorExtractDynamic(uint32_t result_type, uint32_t result_id,
                                      uint32_t vector, uint32_t index);
  InstBuilder &opVectorInsertDynamic(uint32_t result_type, uint32_t result_id,
                                     uint32_t vector, uint32_t component,
                                     uint32_t index);
  InstBuilder &opVectorShuffle(uint32_t result_type, uint32_t result_id,
                               uint32_t vector_1, uint32_t vector_2,
                               std::initializer_list<uint32_t> components);
  InstBuilder &
  opCompositeConstruct(uint32_t result_type, uint32_t result_id,
                       std::initializer_list<uint32_t> constituents);
  InstBuilder &opCompositeExtract(uint32_t result_type, uint32_t result_id,
                                  uint32_t composite,
                                  std::initializer_list<uint32_t> indexes);
  InstBuilder &opCompositeInsert(uint32_t result_type, uint32_t result_id,
                                 uint32_t object, uint32_t composite,
                                 std::initializer_list<uint32_t> indexes);
  InstBuilder &opCopyObject(uint32_t result_type, uint32_t result_id,
                            uint32_t operand);
  InstBuilder &opTranspose(uint32_t result_type, uint32_t result_id,
                           uint32_t matrix);
  InstBuilder &opSampledImage(uint32_t result_type, uint32_t result_id,
                              uint32_t image, uint32_t sampler);
  InstBuilder &
  opImageSampleImplicitLod(uint32_t result_type, uint32_t result_id,
                           uint32_t sampled_image, uint32_t coordinate,
                           Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImageSampleExplicitLod(uint32_t result_type,
                                        uint32_t result_id,
                                        uint32_t sampled_image,
                                        uint32_t coordinate,
                                        spv::ImageOperandsMask image_operands);
  InstBuilder &
  opImageSampleDrefImplicitLod(uint32_t result_type, uint32_t result_id,
                               uint32_t sampled_image, uint32_t coordinate,
                               uint32_t dref,
                               Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &
  opImageSampleDrefExplicitLod(uint32_t result_type, uint32_t result_id,
                               uint32_t sampled_image, uint32_t coordinate,
                               uint32_t dref,
                               spv::ImageOperandsMask image_operands);
  InstBuilder &
  opImageSampleProjImplicitLod(uint32_t result_type, uint32_t result_id,
                               uint32_t sampled_image, uint32_t coordinate,
                               Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &
  opImageSampleProjExplicitLod(uint32_t result_type, uint32_t result_id,
                               uint32_t sampled_image, uint32_t coordinate,
                               spv::ImageOperandsMask image_operands);
  InstBuilder &opImageSampleProjDrefImplicitLod(
      uint32_t result_type, uint32_t result_id, uint32_t sampled_image,
      uint32_t coordinate, uint32_t dref,
      Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &
  opImageSampleProjDrefExplicitLod(uint32_t result_type, uint32_t result_id,
                                   uint32_t sampled_image, uint32_t coordinate,
                                   uint32_t dref,
                                   spv::ImageOperandsMask image_operands);
  InstBuilder &opImageFetch(uint32_t result_type, uint32_t result_id,
                            uint32_t image, uint32_t coordinate,
                            Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImageGather(uint32_t result_type, uint32_t result_id,
                             uint32_t sampled_image, uint32_t coordinate,
                             uint32_t component,
                             Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImageDrefGather(uint32_t result_type, uint32_t result_id,
                                 uint32_t sampled_image, uint32_t coordinate,
                                 uint32_t dref,
                                 Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImageRead(uint32_t result_type, uint32_t result_id,
                           uint32_t image, uint32_t coordinate,
                           Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImageWrite(uint32_t image, uint32_t coordinate, uint32_t texel,
                            Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImage(uint32_t result_type, uint32_t result_id,
                       uint32_t sampled_image);
  InstBuilder &opImageQueryFormat(uint32_t result_type, uint32_t result_id,
                                  uint32_t image);
  InstBuilder &opImageQueryOrder(uint32_t result_type, uint32_t result_id,
                                 uint32_t image);
  InstBuilder &opImageQuerySizeLod(uint32_t result_type, uint32_t result_id,
                                   uint32_t image, uint32_t level_of_detail);
  InstBuilder &opImageQuerySize(uint32_t result_type, uint32_t result_id,
                                uint32_t image);
  InstBuilder &opImageQueryLod(uint32_t result_type, uint32_t result_id,
                               uint32_t sampled_image, uint32_t coordinate);
  InstBuilder &opImageQueryLevels(uint32_t result_type, uint32_t result_id,
                                  uint32_t image);
  InstBuilder &opImageQuerySamples(uint32_t result_type, uint32_t result_id,
                                   uint32_t image);
  InstBuilder &opConvertFToU(uint32_t result_type, uint32_t result_id,
                             uint32_t float_value);
  InstBuilder &opConvertFToS(uint32_t result_type, uint32_t result_id,
                             uint32_t float_value);
  InstBuilder &opConvertSToF(uint32_t result_type, uint32_t result_id,
                             uint32_t signed_value);
  InstBuilder &opConvertUToF(uint32_t result_type, uint32_t result_id,
                             uint32_t unsigned_value);
  InstBuilder &opUConvert(uint32_t result_type, uint32_t result_id,
                          uint32_t unsigned_value);
  InstBuilder &opSConvert(uint32_t result_type, uint32_t result_id,
                          uint32_t signed_value);
  InstBuilder &opFConvert(uint32_t result_type, uint32_t result_id,
                          uint32_t float_value);
  InstBuilder &opQuantizeToF16(uint32_t result_type, uint32_t result_id,
                               uint32_t value);
  InstBuilder &opConvertPtrToU(uint32_t result_type, uint32_t result_id,
                               uint32_t pointer);
  InstBuilder &opSatConvertSToU(uint32_t result_type, uint32_t result_id,
                                uint32_t signed_value);
  InstBuilder &opSatConvertUToS(uint32_t result_type, uint32_t result_id,
                                uint32_t unsigned_value);
  InstBuilder &opConvertUToPtr(uint32_t result_type, uint32_t result_id,
                               uint32_t integer_value);
  InstBuilder &opPtrCastToGeneric(uint32_t result_type, uint32_t result_id,
                                  uint32_t pointer);
  InstBuilder &opGenericCastToPtr(uint32_t result_type, uint32_t result_id,
                                  uint32_t pointer);
  InstBuilder &opGenericCastToPtrExplicit(uint32_t result_type,
                                          uint32_t result_id, uint32_t pointer,
                                          spv::StorageClass storage);
  InstBuilder &opBitcast(uint32_t result_type, uint32_t result_id,
                         uint32_t operand);
  InstBuilder &opSNegate(uint32_t result_type, uint32_t result_id,
                         uint32_t operand);
  InstBuilder &opFNegate(uint32_t result_type, uint32_t result_id,
                         uint32_t operand);
  InstBuilder &opIAdd(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFAdd(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opISub(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFSub(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opIMul(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFMul(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opUDiv(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opSDiv(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFDiv(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opUMod(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opSRem(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opSMod(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFRem(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFMod(uint32_t result_type, uint32_t result_id,
                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opVectorTimesScalar(uint32_t result_type, uint32_t result_id,
                                   uint32_t vector, uint32_t scalar);
  InstBuilder &opMatrixTimesScalar(uint32_t result_type, uint32_t result_id,
                                   uint32_t matrix, uint32_t scalar);
  InstBuilder &opVectorTimesMatrix(uint32_t result_type, uint32_t result_id,
                                   uint32_t vector, uint32_t matrix);
  InstBuilder &opMatrixTimesVector(uint32_t result_type, uint32_t result_id,
                                   uint32_t matrix, uint32_t vector);
  InstBuilder &opMatrixTimesMatrix(uint32_t result_type, uint32_t result_id,
                                   uint32_t left_matrix, uint32_t right_matrix);
  InstBuilder &opOuterProduct(uint32_t result_type, uint32_t result_id,
                              uint32_t vector_1, uint32_t vector_2);
  InstBuilder &opDot(uint32_t result_type, uint32_t result_id,
                     uint32_t vector_1, uint32_t vector_2);
  InstBuilder &opIAddCarry(uint32_t result_type, uint32_t result_id,
                           uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opISubBorrow(uint32_t result_type, uint32_t result_id,
                            uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opUMulExtended(uint32_t result_type, uint32_t result_id,
                              uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opSMulExtended(uint32_t result_type, uint32_t result_id,
                              uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opAny(uint32_t result_type, uint32_t result_id, uint32_t vector);
  InstBuilder &opAll(uint32_t result_type, uint32_t result_id, uint32_t vector);
  InstBuilder &opIsNan(uint32_t result_type, uint32_t result_id, uint32_t x);
  InstBuilder &opIsInf(uint32_t result_type, uint32_t result_id, uint32_t x);
  InstBuilder &opIsFinite(uint32_t result_type, uint32_t result_id, uint32_t x);
  InstBuilder &opIsNormal(uint32_t result_type, uint32_t result_id, uint32_t x);
  InstBuilder &opSignBitSet(uint32_t result_type, uint32_t result_id,
                            uint32_t x);
  InstBuilder &opLessOrGreater(uint32_t result_type, uint32_t result_id,
                               uint32_t x, uint32_t y);
  InstBuilder &opOrdered(uint32_t result_type, uint32_t result_id, uint32_t x,
                         uint32_t y);
  InstBuilder &opUnordered(uint32_t result_type, uint32_t result_id, uint32_t x,
                           uint32_t y);
  InstBuilder &opLogicalEqual(uint32_t result_type, uint32_t result_id,
                              uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opLogicalNotEqual(uint32_t result_type, uint32_t result_id,
                                 uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opLogicalOr(uint32_t result_type, uint32_t result_id,
                           uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opLogicalAnd(uint32_t result_type, uint32_t result_id,
                            uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opLogicalNot(uint32_t result_type, uint32_t result_id,
                            uint32_t operand);
  InstBuilder &opSelect(uint32_t result_type, uint32_t result_id,
                        uint32_t condition, uint32_t object_1,
                        uint32_t object_2);
  InstBuilder &opIEqual(uint32_t result_type, uint32_t result_id,
                        uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opINotEqual(uint32_t result_type, uint32_t result_id,
                           uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opUGreaterThan(uint32_t result_type, uint32_t result_id,
                              uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opSGreaterThan(uint32_t result_type, uint32_t result_id,
                              uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opUGreaterThanEqual(uint32_t result_type, uint32_t result_id,
                                   uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opSGreaterThanEqual(uint32_t result_type, uint32_t result_id,
                                   uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opULessThan(uint32_t result_type, uint32_t result_id,
                           uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opSLessThan(uint32_t result_type, uint32_t result_id,
                           uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opULessThanEqual(uint32_t result_type, uint32_t result_id,
                                uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opSLessThanEqual(uint32_t result_type, uint32_t result_id,
                                uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFOrdEqual(uint32_t result_type, uint32_t result_id,
                           uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFUnordEqual(uint32_t result_type, uint32_t result_id,
                             uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFOrdNotEqual(uint32_t result_type, uint32_t result_id,
                              uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFUnordNotEqual(uint32_t result_type, uint32_t result_id,
                                uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFOrdLessThan(uint32_t result_type, uint32_t result_id,
                              uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFUnordLessThan(uint32_t result_type, uint32_t result_id,
                                uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFOrdGreaterThan(uint32_t result_type, uint32_t result_id,
                                 uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFUnordGreaterThan(uint32_t result_type, uint32_t result_id,
                                   uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFOrdLessThanEqual(uint32_t result_type, uint32_t result_id,
                                   uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFUnordLessThanEqual(uint32_t result_type, uint32_t result_id,
                                     uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFOrdGreaterThanEqual(uint32_t result_type, uint32_t result_id,
                                      uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opFUnordGreaterThanEqual(uint32_t result_type,
                                        uint32_t result_id, uint32_t operand_1,
                                        uint32_t operand_2);
  InstBuilder &opShiftRightLogical(uint32_t result_type, uint32_t result_id,
                                   uint32_t base, uint32_t shift);
  InstBuilder &opShiftRightArithmetic(uint32_t result_type, uint32_t result_id,
                                      uint32_t base, uint32_t shift);
  InstBuilder &opShiftLeftLogical(uint32_t result_type, uint32_t result_id,
                                  uint32_t base, uint32_t shift);
  InstBuilder &opBitwiseOr(uint32_t result_type, uint32_t result_id,
                           uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opBitwiseXor(uint32_t result_type, uint32_t result_id,
                            uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opBitwiseAnd(uint32_t result_type, uint32_t result_id,
                            uint32_t operand_1, uint32_t operand_2);
  InstBuilder &opNot(uint32_t result_type, uint32_t result_id,
                     uint32_t operand);
  InstBuilder &opBitFieldInsert(uint32_t result_type, uint32_t result_id,
                                uint32_t base, uint32_t insert, uint32_t offset,
                                uint32_t count);
  InstBuilder &opBitFieldSExtract(uint32_t result_type, uint32_t result_id,
                                  uint32_t base, uint32_t offset,
                                  uint32_t count);
  InstBuilder &opBitFieldUExtract(uint32_t result_type, uint32_t result_id,
                                  uint32_t base, uint32_t offset,
                                  uint32_t count);
  InstBuilder &opBitReverse(uint32_t result_type, uint32_t result_id,
                            uint32_t base);
  InstBuilder &opBitCount(uint32_t result_type, uint32_t result_id,
                          uint32_t base);
  InstBuilder &opDPdx(uint32_t result_type, uint32_t result_id, uint32_t p);
  InstBuilder &opDPdy(uint32_t result_type, uint32_t result_id, uint32_t p);
  InstBuilder &opFwidth(uint32_t result_type, uint32_t result_id, uint32_t p);
  InstBuilder &opDPdxFine(uint32_t result_type, uint32_t result_id, uint32_t p);
  InstBuilder &opDPdyFine(uint32_t result_type, uint32_t result_id, uint32_t p);
  InstBuilder &opFwidthFine(uint32_t result_type, uint32_t result_id,
                            uint32_t p);
  InstBuilder &opDPdxCoarse(uint32_t result_type, uint32_t result_id,
                            uint32_t p);
  InstBuilder &opDPdyCoarse(uint32_t result_type, uint32_t result_id,
                            uint32_t p);
  InstBuilder &opFwidthCoarse(uint32_t result_type, uint32_t result_id,
                              uint32_t p);
  InstBuilder &opEmitVertex();
  InstBuilder &opEndPrimitive();
  InstBuilder &opEmitStreamVertex(uint32_t stream);
  InstBuilder &opEndStreamPrimitive(uint32_t stream);
  InstBuilder &opControlBarrier(uint32_t execution, uint32_t memory,
                                uint32_t semantics);
  InstBuilder &opMemoryBarrier(uint32_t memory, uint32_t semantics);
  InstBuilder &opAtomicLoad(uint32_t result_type, uint32_t result_id,
                            uint32_t pointer, uint32_t scope,
                            uint32_t semantics);
  InstBuilder &opAtomicStore(uint32_t pointer, uint32_t scope,
                             uint32_t semantics, uint32_t value);
  InstBuilder &opAtomicExchange(uint32_t result_type, uint32_t result_id,
                                uint32_t pointer, uint32_t scope,
                                uint32_t semantics, uint32_t value);
  InstBuilder &opAtomicCompareExchange(uint32_t result_type, uint32_t result_id,
                                       uint32_t pointer, uint32_t scope,
                                       uint32_t equal, uint32_t unequal,
                                       uint32_t value, uint32_t comparator);
  InstBuilder &opAtomicCompareExchangeWeak(uint32_t result_type,
                                           uint32_t result_id, uint32_t pointer,
                                           uint32_t scope, uint32_t equal,
                                           uint32_t unequal, uint32_t value,
                                           uint32_t comparator);
  InstBuilder &opAtomicIIncrement(uint32_t result_type, uint32_t result_id,
                                  uint32_t pointer, uint32_t scope,
                                  uint32_t semantics);
  InstBuilder &opAtomicIDecrement(uint32_t result_type, uint32_t result_id,
                                  uint32_t pointer, uint32_t scope,
                                  uint32_t semantics);
  InstBuilder &opAtomicIAdd(uint32_t result_type, uint32_t result_id,
                            uint32_t pointer, uint32_t scope,
                            uint32_t semantics, uint32_t value);
  InstBuilder &opAtomicISub(uint32_t result_type, uint32_t result_id,
                            uint32_t pointer, uint32_t scope,
                            uint32_t semantics, uint32_t value);
  InstBuilder &opAtomicSMin(uint32_t result_type, uint32_t result_id,
                            uint32_t pointer, uint32_t scope,
                            uint32_t semantics, uint32_t value);
  InstBuilder &opAtomicUMin(uint32_t result_type, uint32_t result_id,
                            uint32_t pointer, uint32_t scope,
                            uint32_t semantics, uint32_t value);
  InstBuilder &opAtomicSMax(uint32_t result_type, uint32_t result_id,
                            uint32_t pointer, uint32_t scope,
                            uint32_t semantics, uint32_t value);
  InstBuilder &opAtomicUMax(uint32_t result_type, uint32_t result_id,
                            uint32_t pointer, uint32_t scope,
                            uint32_t semantics, uint32_t value);
  InstBuilder &opAtomicAnd(uint32_t result_type, uint32_t result_id,
                           uint32_t pointer, uint32_t scope, uint32_t semantics,
                           uint32_t value);
  InstBuilder &opAtomicOr(uint32_t result_type, uint32_t result_id,
                          uint32_t pointer, uint32_t scope, uint32_t semantics,
                          uint32_t value);
  InstBuilder &opAtomicXor(uint32_t result_type, uint32_t result_id,
                           uint32_t pointer, uint32_t scope, uint32_t semantics,
                           uint32_t value);
  InstBuilder &
  opPhi(uint32_t result_type, uint32_t result_id,
        std::initializer_list<std::pair<uint32_t, uint32_t>> variable_parent_);
  InstBuilder &opLoopMerge(uint32_t merge_block, uint32_t continue_target,
                           spv::LoopControlMask loop_control);
  InstBuilder &opSelectionMerge(uint32_t merge_block,
                                spv::SelectionControlMask selection_control);
  InstBuilder &opLabel(uint32_t result_id);
  InstBuilder &opBranch(uint32_t target_label);
  InstBuilder &
  opBranchConditional(uint32_t condition, uint32_t true_label,
                      uint32_t false_label,
                      std::initializer_list<uint32_t> branch_weights);
  InstBuilder &
  opSwitch(uint32_t selector, uint32_t default_target,
           std::initializer_list<std::pair<uint32_t, uint32_t>> target);
  InstBuilder &opKill();
  InstBuilder &opReturn();
  InstBuilder &opReturnValue(uint32_t value);
  InstBuilder &opUnreachable();
  InstBuilder &opLifetimeStart(uint32_t pointer, uint32_t size);
  InstBuilder &opLifetimeStop(uint32_t pointer, uint32_t size);
  InstBuilder &opGroupAsyncCopy(uint32_t result_type, uint32_t result_id,
                                uint32_t execution, uint32_t destination,
                                uint32_t source, uint32_t num_elements,
                                uint32_t stride, uint32_t event);
  InstBuilder &opGroupWaitEvents(uint32_t execution, uint32_t num_events,
                                 uint32_t events_list);
  InstBuilder &opGroupAll(uint32_t result_type, uint32_t result_id,
                          uint32_t execution, uint32_t predicate);
  InstBuilder &opGroupAny(uint32_t result_type, uint32_t result_id,
                          uint32_t execution, uint32_t predicate);
  InstBuilder &opGroupBroadcast(uint32_t result_type, uint32_t result_id,
                                uint32_t execution, uint32_t value,
                                uint32_t local_id);
  InstBuilder &opGroupIAdd(uint32_t result_type, uint32_t result_id,
                           uint32_t execution, spv::GroupOperation operation,
                           uint32_t x);
  InstBuilder &opGroupFAdd(uint32_t result_type, uint32_t result_id,
                           uint32_t execution, spv::GroupOperation operation,
                           uint32_t x);
  InstBuilder &opGroupFMin(uint32_t result_type, uint32_t result_id,
                           uint32_t execution, spv::GroupOperation operation,
                           uint32_t x);
  InstBuilder &opGroupUMin(uint32_t result_type, uint32_t result_id,
                           uint32_t execution, spv::GroupOperation operation,
                           uint32_t x);
  InstBuilder &opGroupSMin(uint32_t result_type, uint32_t result_id,
                           uint32_t execution, spv::GroupOperation operation,
                           uint32_t x);
  InstBuilder &opGroupFMax(uint32_t result_type, uint32_t result_id,
                           uint32_t execution, spv::GroupOperation operation,
                           uint32_t x);
  InstBuilder &opGroupUMax(uint32_t result_type, uint32_t result_id,
                           uint32_t execution, spv::GroupOperation operation,
                           uint32_t x);
  InstBuilder &opGroupSMax(uint32_t result_type, uint32_t result_id,
                           uint32_t execution, spv::GroupOperation operation,
                           uint32_t x);
  InstBuilder &opReadPipe(uint32_t result_type, uint32_t result_id,
                          uint32_t pipe, uint32_t pointer, uint32_t packet_size,
                          uint32_t packet_alignment);
  InstBuilder &opWritePipe(uint32_t result_type, uint32_t result_id,
                           uint32_t pipe, uint32_t pointer,
                           uint32_t packet_size, uint32_t packet_alignment);
  InstBuilder &opReservedReadPipe(uint32_t result_type, uint32_t result_id,
                                  uint32_t pipe, uint32_t reserve_id,
                                  uint32_t index, uint32_t pointer,
                                  uint32_t packet_size,
                                  uint32_t packet_alignment);
  InstBuilder &opReservedWritePipe(uint32_t result_type, uint32_t result_id,
                                   uint32_t pipe, uint32_t reserve_id,
                                   uint32_t index, uint32_t pointer,
                                   uint32_t packet_size,
                                   uint32_t packet_alignment);
  InstBuilder &opReserveReadPipePackets(uint32_t result_type,
                                        uint32_t result_id, uint32_t pipe,
                                        uint32_t num_packets,
                                        uint32_t packet_size,
                                        uint32_t packet_alignment);
  InstBuilder &opReserveWritePipePackets(uint32_t result_type,
                                         uint32_t result_id, uint32_t pipe,
                                         uint32_t num_packets,
                                         uint32_t packet_size,
                                         uint32_t packet_alignment);
  InstBuilder &opCommitReadPipe(uint32_t pipe, uint32_t reserve_id,
                                uint32_t packet_size,
                                uint32_t packet_alignment);
  InstBuilder &opCommitWritePipe(uint32_t pipe, uint32_t reserve_id,
                                 uint32_t packet_size,
                                 uint32_t packet_alignment);
  InstBuilder &opIsValidReserveId(uint32_t result_type, uint32_t result_id,
                                  uint32_t reserve_id);
  InstBuilder &opGetNumPipePackets(uint32_t result_type, uint32_t result_id,
                                   uint32_t pipe, uint32_t packet_size,
                                   uint32_t packet_alignment);
  InstBuilder &opGetMaxPipePackets(uint32_t result_type, uint32_t result_id,
                                   uint32_t pipe, uint32_t packet_size,
                                   uint32_t packet_alignment);
  InstBuilder &opGroupReserveReadPipePackets(uint32_t result_type,
                                             uint32_t result_id,
                                             uint32_t execution, uint32_t pipe,
                                             uint32_t num_packets,
                                             uint32_t packet_size,
                                             uint32_t packet_alignment);
  InstBuilder &opGroupReserveWritePipePackets(uint32_t result_type,
                                              uint32_t result_id,
                                              uint32_t execution, uint32_t pipe,
                                              uint32_t num_packets,
                                              uint32_t packet_size,
                                              uint32_t packet_alignment);
  InstBuilder &opGroupCommitReadPipe(uint32_t execution, uint32_t pipe,
                                     uint32_t reserve_id, uint32_t packet_size,
                                     uint32_t packet_alignment);
  InstBuilder &opGroupCommitWritePipe(uint32_t execution, uint32_t pipe,
                                      uint32_t reserve_id, uint32_t packet_size,
                                      uint32_t packet_alignment);
  InstBuilder &opEnqueueMarker(uint32_t result_type, uint32_t result_id,
                               uint32_t queue, uint32_t num_events,
                               uint32_t wait_events, uint32_t ret_event);
  InstBuilder &opEnqueueKernel(uint32_t result_type, uint32_t result_id,
                               uint32_t queue, uint32_t flags,
                               uint32_t nd_range, uint32_t num_events,
                               uint32_t wait_events, uint32_t ret_event,
                               uint32_t invoke, uint32_t param,
                               uint32_t param_size, uint32_t param_align,
                               std::initializer_list<uint32_t> local_size);
  InstBuilder &opGetKernelNDrangeSubGroupCount(uint32_t result_type,
                                               uint32_t result_id,
                                               uint32_t nd_range,
                                               uint32_t invoke, uint32_t param,
                                               uint32_t param_size,
                                               uint32_t param_align);
  InstBuilder &
  opGetKernelNDrangeMaxSubGroupSize(uint32_t result_type, uint32_t result_id,
                                    uint32_t nd_range, uint32_t invoke,
                                    uint32_t param, uint32_t param_size,
                                    uint32_t param_align);
  InstBuilder &opGetKernelWorkGroupSize(uint32_t result_type,
                                        uint32_t result_id, uint32_t invoke,
                                        uint32_t param, uint32_t param_size,
                                        uint32_t param_align);
  InstBuilder &opGetKernelPreferredWorkGroupSizeMultiple(
      uint32_t result_type, uint32_t result_id, uint32_t invoke, uint32_t param,
      uint32_t param_size, uint32_t param_align);
  InstBuilder &opRetainEvent(uint32_t event);
  InstBuilder &opReleaseEvent(uint32_t event);
  InstBuilder &opCreateUserEvent(uint32_t result_type, uint32_t result_id);
  InstBuilder &opIsValidEvent(uint32_t result_type, uint32_t result_id,
                              uint32_t event);
  InstBuilder &opSetUserEventStatus(uint32_t event, uint32_t status);
  InstBuilder &opCaptureEventProfilingInfo(uint32_t event,
                                           uint32_t profiling_info,
                                           uint32_t value);
  InstBuilder &opGetDefaultQueue(uint32_t result_type, uint32_t result_id);
  InstBuilder &opBuildNDRange(uint32_t result_type, uint32_t result_id,
                              uint32_t global_work_size,
                              uint32_t local_work_size,
                              uint32_t global_work_offset);
  InstBuilder &
  opImageSparseSampleImplicitLod(uint32_t result_type, uint32_t result_id,
                                 uint32_t sampled_image, uint32_t coordinate,
                                 Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &
  opImageSparseSampleExplicitLod(uint32_t result_type, uint32_t result_id,
                                 uint32_t sampled_image, uint32_t coordinate,
                                 spv::ImageOperandsMask image_operands);
  InstBuilder &opImageSparseSampleDrefImplicitLod(
      uint32_t result_type, uint32_t result_id, uint32_t sampled_image,
      uint32_t coordinate, uint32_t dref,
      Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &
  opImageSparseSampleDrefExplicitLod(uint32_t result_type, uint32_t result_id,
                                     uint32_t sampled_image,
                                     uint32_t coordinate, uint32_t dref,
                                     spv::ImageOperandsMask image_operands);
  InstBuilder &opImageSparseSampleProjImplicitLod(
      uint32_t result_type, uint32_t result_id, uint32_t sampled_image,
      uint32_t coordinate, Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImageSparseSampleProjExplicitLod(
      uint32_t result_type, uint32_t result_id, uint32_t sampled_image,
      uint32_t coordinate, spv::ImageOperandsMask image_operands);
  InstBuilder &opImageSparseSampleProjDrefImplicitLod(
      uint32_t result_type, uint32_t result_id, uint32_t sampled_image,
      uint32_t coordinate, uint32_t dref,
      Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImageSparseSampleProjDrefExplicitLod(
      uint32_t result_type, uint32_t result_id, uint32_t sampled_image,
      uint32_t coordinate, uint32_t dref,
      spv::ImageOperandsMask image_operands);
  InstBuilder &
  opImageSparseFetch(uint32_t result_type, uint32_t result_id, uint32_t image,
                     uint32_t coordinate,
                     Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &
  opImageSparseGather(uint32_t result_type, uint32_t result_id,
                      uint32_t sampled_image, uint32_t coordinate,
                      uint32_t component,
                      Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &
  opImageSparseDrefGather(uint32_t result_type, uint32_t result_id,
                          uint32_t sampled_image, uint32_t coordinate,
                          uint32_t dref,
                          Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opImageSparseTexelsResident(uint32_t result_type,
                                           uint32_t result_id,
                                           uint32_t resident_code);
  InstBuilder &opNoLine();
  InstBuilder &opAtomicFlagTestAndSet(uint32_t result_type, uint32_t result_id,
                                      uint32_t pointer, uint32_t scope,
                                      uint32_t semantics);
  InstBuilder &opAtomicFlagClear(uint32_t pointer, uint32_t scope,
                                 uint32_t semantics);
  InstBuilder &opImageSparseRead(uint32_t result_type, uint32_t result_id,
                                 uint32_t image, uint32_t coordinate,
                                 Option<spv::ImageOperandsMask> image_operands);
  InstBuilder &opSizeOf(uint32_t result_type, uint32_t result_id,
                        uint32_t pointer);
  InstBuilder &opTypePipeStorage(uint32_t result_id);
  InstBuilder &opConstantPipeStorage(uint32_t result_type, uint32_t result_id,
                                     uint32_t packet_size,
                                     uint32_t packet_alignment,
                                     uint32_t capacity);
  InstBuilder &opCreatePipeFromPipeStorage(uint32_t result_type,
                                           uint32_t result_id,
                                           uint32_t pipe_storage);
  InstBuilder &
  opGetKernelLocalSizeForSubgroupCount(uint32_t result_type, uint32_t result_id,
                                       uint32_t subgroup_count, uint32_t invoke,
                                       uint32_t param, uint32_t param_size,
                                       uint32_t param_align);
  InstBuilder &opGetKernelMaxNumSubgroups(uint32_t result_type,
                                          uint32_t result_id, uint32_t invoke,
                                          uint32_t param, uint32_t param_size,
                                          uint32_t param_align);
  InstBuilder &opTypeNamedBarrier(uint32_t result_id);
  InstBuilder &opNamedBarrierInitialize(uint32_t result_type,
                                        uint32_t result_id,
                                        uint32_t subgroup_count);
  InstBuilder &opMemoryNamedBarrier(uint32_t named_barrier, uint32_t memory,
                                    uint32_t semantics);
  InstBuilder &opModuleProcessed(std::string process);
  InstBuilder &opSubgroupBallotKHR(uint32_t result_type, uint32_t result_id,
                                   uint32_t predicate);
  InstBuilder &opSubgroupFirstInvocationKHR(uint32_t result_type,
                                            uint32_t result_id, uint32_t value);
  InstBuilder &opSubgroupAllKHR(uint32_t result_type, uint32_t result_id,
                                uint32_t predicate);
  InstBuilder &opSubgroupAnyKHR(uint32_t result_type, uint32_t result_id,
                                uint32_t predicate);
  InstBuilder &opSubgroupAllEqualKHR(uint32_t result_type, uint32_t result_id,
                                     uint32_t predicate);
  InstBuilder &opSubgroupReadInvocationKHR(uint32_t result_type,
                                           uint32_t result_id, uint32_t value,
                                           uint32_t index);

  // Methods for supplying additional parameters.
  InstBuilder &fPFastMathMode(spv::FPFastMathModeMask);
  InstBuilder &fPRoundingMode(spv::FPRoundingMode);
  InstBuilder &linkageType(spv::LinkageType);
  InstBuilder &functionParameterAttribute(spv::FunctionParameterAttribute);
  InstBuilder &builtIn(spv::BuiltIn);
  InstBuilder &idRef(uint32_t);
  InstBuilder &literalInteger(uint32_t);
  InstBuilder &literalString(std::string);

private:
  enum class OperandKind {
    BuiltIn,
    FPFastMathMode,
    FPRoundingMode,
    FunctionParameterAttribute,
    IdRef,
    LinkageType,
    LiteralInteger,
    LiteralString
  };

  void encodeImageOperands(spv::ImageOperandsMask value);
  void encodeLoopControl(spv::LoopControlMask value);
  void encodeMemoryAccess(spv::MemoryAccessMask value);
  void encodeExecutionMode(spv::ExecutionMode value);
  void encodeDecoration(spv::Decoration value);
  void encodeString(std::string value);

  std::vector<uint32_t> TheInst;
  std::deque<OperandKind> Expectation;
  Status TheStatus;
};

} // end namespace spirv
} // end namespace clang

#endif