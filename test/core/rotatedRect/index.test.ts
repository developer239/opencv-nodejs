import { RotatedRect, Point2, Size } from '../../../index'

describe('[core] RotatedRect', () => {
  describe('constructor', () => {
    it('initializes', () => {
      const rotatedRect = new RotatedRect(
        new Point2(10, 20),
        new Size(30, 40),
        50,
      )

      expect(rotatedRect.angle).toStrictEqual(50)
      expect(rotatedRect.center.x).toStrictEqual(10)
      expect(rotatedRect.center.y).toStrictEqual(20)
      expect(rotatedRect.size.width).toStrictEqual(30)
      expect(rotatedRect.size.height).toStrictEqual(40)
    })

    describe('center', () => {
      describe('when center instance property changes', () => {
        it('should change center in the rectangle', () => {
          const center = new Point2(10, 20)

          const rotatedRect = new RotatedRect(
            center,
            new Size(30, 40),
            50,
          )

          expect(rotatedRect.center.x).toStrictEqual(10)
          expect(rotatedRect.center.y).toStrictEqual(20)

          center.x = 88
          center.y = 99

          expect(center.x).toStrictEqual(88)
          expect(center.y).toStrictEqual(99)

          expect(rotatedRect.center.x).toStrictEqual(88)
          expect(rotatedRect.center.y).toStrictEqual(99)
        })
      })

      describe('when center in the rectangle changes', () => {
        it('should change property of the center instance', () => {
          const center = new Point2(10, 20)

          const rotatedRect = new RotatedRect(
            center,
            new Size(30, 40),
            50,
          )

          expect(rotatedRect.center.x).toStrictEqual(10)
          expect(rotatedRect.center.y).toStrictEqual(20)

          rotatedRect.center.x = 88
          rotatedRect.center.y = 77

          expect(rotatedRect.center.x).toStrictEqual(88)
          expect(rotatedRect.center.y).toStrictEqual(77)

          expect(center.x).toStrictEqual(88)
          expect(center.y).toStrictEqual(77)
        })
      })
    })

    describe('size', () => {
      describe('when size instance property changes', () => {
        it('should change size in the rectangle', () => {
          const size = new Size(30, 40)

          const rotatedRect = new RotatedRect(
            new Point2(10, 20),
            size,
            50,
          )

          expect(size.width).toStrictEqual(30)
          expect(size.height).toStrictEqual(40)

          size.width = 88
          size.height = 99

          expect(size.width).toStrictEqual(88)
          expect(size.height).toStrictEqual(99)

          expect(rotatedRect.size.width).toStrictEqual(88)
          expect(rotatedRect.size.height).toStrictEqual(99)
        })
      })

      describe('when size in the rectangle changes', () => {
        it('should change property of the size instance', () => {
          const size = new Size(30, 40)

          const rotatedRect = new RotatedRect(
            new Point2(10, 20),
            size,
            50,
          )

          expect(rotatedRect.size.width).toStrictEqual(30)
          expect(rotatedRect.size.height).toStrictEqual(40)

          rotatedRect.size.width = 88
          rotatedRect.size.height = 77

          expect(rotatedRect.size.width).toStrictEqual(88)
          expect(rotatedRect.size.height).toStrictEqual(77)

          expect(size.width).toStrictEqual(88)
          expect(size.height).toStrictEqual(77)
        })
      })
    })
  })
})
