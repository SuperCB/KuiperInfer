//
// Created by fss on 22-12-18.
//

#include <gtest/gtest.h>
#include <glog/logging.h>

#include "data/tensor.hpp"
#include "../source/layer/details/sigmoid.hpp"

TEST(test_layer, forward_sigmoid1) {
  using namespace kuiper_infer;
  std::shared_ptr<Tensor<float>> input = std::make_shared<Tensor<float>>(3, 32, 32);
  input->Rand();
  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input);
  std::vector<std::shared_ptr<Tensor<float>>> outputs;
  std::shared_ptr<Tensor<float>> output1 = std::make_shared<Tensor<float>>(3, 32, 32);
  outputs.push_back(output1);

  std::shared_ptr<Tensor<float>> output2 = input->Clone();
  output2->data() = 1 / (1 + arma::exp(-output2->data()));
  SigmoidLayer sigmoid_layer;
  const auto status = sigmoid_layer.Forward(inputs, outputs);
  ASSERT_EQ(status, InferStatus::kInferSuccess);

  ASSERT_EQ(outputs.size(), 1);
  uint32_t size1 = outputs.front()->size();
  uint32_t size2 = output2->size();
  ASSERT_EQ(size1, size2);
  for (uint32_t i = 0; i < size1; ++i) {
    ASSERT_EQ(outputs.front()->index(i), output2->index(i));
  }
}

TEST(test_layer, forward_sigmoid2) {
  using namespace kuiper_infer;
  std::shared_ptr<Tensor<float>> input = std::make_shared<Tensor<float>>(3, 32, 32);
  input->Ones();
  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input);
  std::vector<std::shared_ptr<Tensor<float>>> outputs;
  std::shared_ptr<Tensor<float>> output1 = std::make_shared<Tensor<float>>(3, 32, 32);
  outputs.push_back(output1);

  std::shared_ptr<Tensor<float>> output2 = input->Clone();
  output2->data() = 1 / (1 + arma::exp(-output2->data()));
  SigmoidLayer sigmoid_layer;
  const auto status = sigmoid_layer.Forward(inputs, outputs);
  ASSERT_EQ(status, InferStatus::kInferSuccess);

  ASSERT_EQ(outputs.size(), 1);
  uint32_t size1 = outputs.front()->size();
  uint32_t size2 = output2->size();
  ASSERT_EQ(size1, size2);
  for (uint32_t i = 0; i < size1; ++i) {
    ASSERT_EQ(outputs.front()->index(i), output2->index(i));
  }
}

TEST(test_layer, forward_sigmoid3) {
  using namespace kuiper_infer;
  std::shared_ptr<Tensor<float>> input = std::make_shared<Tensor<float>>(1, 32, 1);
  input->Rand();
  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input);
  std::vector<std::shared_ptr<Tensor<float>>> outputs;
  std::shared_ptr<Tensor<float>> output1 = std::make_shared<Tensor<float>>(1, 32, 1);
  outputs.push_back(output1);

  std::shared_ptr<Tensor<float>> output2 = input->Clone();
  output2->data() = 1 / (1 + arma::exp(-output2->data()));
  SigmoidLayer sigmoid_layer;
  const auto status = sigmoid_layer.Forward(inputs, outputs);
  ASSERT_EQ(status, InferStatus::kInferSuccess);

  ASSERT_EQ(outputs.size(), 1);
  uint32_t size1 = outputs.front()->size();
  uint32_t size2 = output2->size();
  ASSERT_EQ(size1, size2);
  for (uint32_t i = 0; i < size1; ++i) {
    ASSERT_EQ(outputs.front()->index(i), output2->index(i));
  }
}

TEST(test_layer, forward_sigmoid4) {
  using namespace kuiper_infer;
  std::shared_ptr<Tensor<float>> input = std::make_shared<Tensor<float>>(1, 32, 1);
  input->Ones();
  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input);
  std::vector<std::shared_ptr<Tensor<float>>> outputs;
  std::shared_ptr<Tensor<float>> output1 = std::make_shared<Tensor<float>>(1, 32, 1);
  outputs.push_back(output1);

  std::shared_ptr<Tensor<float>> output2 = input->Clone();
  output2->data() = 1 / (1 + arma::exp(-output2->data()));
  SigmoidLayer sigmoid_layer;
  const auto status = sigmoid_layer.Forward(inputs, outputs);
  ASSERT_EQ(status, InferStatus::kInferSuccess);

  ASSERT_EQ(outputs.size(), 1);
  uint32_t size1 = outputs.front()->size();
  uint32_t size2 = output2->size();
  ASSERT_EQ(size1, size2);
  for (uint32_t i = 0; i < size1; ++i) {
    ASSERT_EQ(outputs.front()->index(i), output2->index(i));
  }
}

TEST(test_layer, forward_sigmoid5) {
  using namespace kuiper_infer;
  std::shared_ptr<Tensor<float>> input = std::make_shared<Tensor<float>>(1, 1, 32);
  input->Rand();
  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input);
  std::vector<std::shared_ptr<Tensor<float>>> outputs;
  std::shared_ptr<Tensor<float>> output1 = std::make_shared<Tensor<float>>(1, 1, 32);
  outputs.push_back(output1);

  std::shared_ptr<Tensor<float>> output2 = input->Clone();
  output2->data() = 1 / (1 + arma::exp(-output2->data()));
  SigmoidLayer sigmoid_layer;
  const auto status = sigmoid_layer.Forward(inputs, outputs);
  ASSERT_EQ(status, InferStatus::kInferSuccess);

  ASSERT_EQ(outputs.size(), 1);
  uint32_t size1 = outputs.front()->size();
  uint32_t size2 = output2->size();
  ASSERT_EQ(size1, size2);
  for (uint32_t i = 0; i < size1; ++i) {
    ASSERT_EQ(outputs.front()->index(i), output2->index(i));
  }
}

TEST(test_layer, forward_sigmoid6) {
  using namespace kuiper_infer;
  std::shared_ptr<Tensor<float>> input = std::make_shared<Tensor<float>>(1, 1, 4);
  input->index(0) = 1.f;
  input->index(1) = 2.f;
  input->index(2) = 3.f;
  input->index(3) = 4.f;

  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input);
  std::vector<std::shared_ptr<Tensor<float>>> outputs;
  std::shared_ptr<Tensor<float>> output1 = std::make_shared<Tensor<float>>(1, 1, 4);
  outputs.push_back(output1);

  SigmoidLayer sigmoid_layer;
  const auto status = sigmoid_layer.Forward(inputs, outputs);
  ASSERT_EQ(status, InferStatus::kInferSuccess);
  ASSERT_LE(std::abs(outputs.front()->index(0) - 0.7310585786300049f), 1e-6);
  ASSERT_LE(std::abs(outputs.front()->index(1) - 0.8807970779778823f), 1e-6);
  ASSERT_LE(std::abs(outputs.front()->index(2) - 0.9525741268224334f), 1e-6);
  ASSERT_LE(std::abs(outputs.front()->index(3) - 0.9820137900379085f), 1e-6);
}