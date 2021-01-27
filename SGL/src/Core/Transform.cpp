#include "Transform.h"

namespace SGL {

    /* ***************************************************************************************** */
    Transform::Transform(
    ) {
        m_WorldMatrix4.identity();
        m_Position = Vector3<float>::zero();
        m_Rotation = Vector3<float>::zero();
        m_Scale = Vector3<float>::one();
    }


    /* ***************************************************************************************** */
    Transform::~Transform(
    ) noexcept {
        m_WorldMatrix4.identity();
        m_Position = Vector3<float>::zero();
        m_Rotation = Vector3<float>::zero();
        m_Scale = Vector3<float>::one();
    }


    /* ***************************************************************************************** */
    auto Transform::translate(
        const Vector3<float>& translation
    ) noexcept -> void {
        auto oldScale = m_Scale;
        auto oldRotation = m_Rotation;
        setLocalScale(Vector3<float>::one());
        setRotation(Vector3<float>::zero());
        m_WorldMatrix4.translate(translation);
        m_Position += translation;
        setRotation(oldRotation);
        setLocalScale(oldScale);
    }


    /* ***************************************************************************************** */
    auto Transform::setPosition(
        const Vector3<float>& newPosition
    ) noexcept -> void {
        auto scale = m_Scale;
        setLocalScale(Vector3<float>::one());
        m_WorldMatrix4.translate(Vector3<float>::zero() - m_Position);
        m_Position = newPosition;
        m_WorldMatrix4.translate(m_Position);
        setLocalScale(scale);
    }


    /* ***************************************************************************************** */
    auto Transform::getPosition(
    ) const noexcept -> Vector3<float> {
        return m_Position;
    }


    /* ***************************************************************************************** */
    auto Transform::rotate(
        const Vector3<float>& rotation
    ) noexcept -> void {
        m_WorldMatrix4.rotate(rotation);
        m_Rotation += rotation;
    }


    /* ***************************************************************************************** */
    auto Transform::rotateAround(
        const Vector3<float>& point,
        const Vector3<float>& rotation
    ) noexcept -> void {
        m_WorldMatrix4.translate(point);
        m_WorldMatrix4.rotate(rotation);
        m_WorldMatrix4.translate(Vector3<float>::zero() - point);
        m_Rotation += rotation;
    }


    /* ***************************************************************************************** */
    auto Transform::setRotation(
        const Vector3<float>& newRotation
    ) noexcept -> void {
        m_WorldMatrix4.rotate(Vector3<float>::zero() - m_Rotation);
        m_Rotation = newRotation;
        m_WorldMatrix4.rotate(m_Rotation);
    }


    /* ***************************************************************************************** */
    auto Transform::setRotationAround(
        const Vector3<float>& point,
        const Vector3<float>& newRotation
    ) noexcept -> void {
        m_WorldMatrix4.translate(point);
        m_WorldMatrix4.rotate(Vector3<float>::zero() - m_Rotation);
        m_Rotation = newRotation;
        m_WorldMatrix4.rotate(m_Rotation);
        m_WorldMatrix4.translate(Vector3<float>::zero() - point);
    }


    /* ***************************************************************************************** */
    auto Transform::getRotation(
    ) const noexcept -> Vector3<float> {
        return m_Rotation;
    }


    /* ***************************************************************************************** */
    auto Transform::setLocalScale(
        const Vector3<float>& newScale
    ) noexcept -> void {
        m_WorldMatrix4.scale({1.0f / m_Scale.x, 1.0f / m_Scale.y, 1.0f / m_Scale.z});
        m_Scale = newScale;
        m_WorldMatrix4.scale(m_Scale);
    }


    /* ***************************************************************************************** */
    auto Transform::setLocalScaleAround(
        const Vector3<float>& point,
        const Vector3<float>& newScale
    ) noexcept -> void {
        m_WorldMatrix4.translate(point);
        m_WorldMatrix4.scale({ 1.0f / m_Scale.x, 1.0f / m_Scale.y, 1.0f / m_Scale.z });
        m_Scale = newScale;
        m_WorldMatrix4.scale(m_Scale);
        m_WorldMatrix4.translate(Vector3<float>::zero() - point);
    }


    /* ***************************************************************************************** */
    auto Transform::getLocalScale(
    ) const noexcept -> Vector3<float> {
        return m_Scale;
    }


    /* ***************************************************************************************** */
    auto Transform::getWorldMatrix(
    ) const noexcept -> Matrix4 {
        return m_WorldMatrix4;
    }

}